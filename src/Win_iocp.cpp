// IOCP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <process.h>
using namespace std;

//完成键
#define CK_READ  1
#define CK_WRITE 2

void ShowErrMsg(LPCSTR lpMsg);



int main(int argc, char* argv[])
{

	LPCTSTR lpSrc = TEXT("D:\\超大文件.zip");
	LPCTSTR lpDest = TEXT("D:\\换个名字.zip");


	HANDLE hSrcFile = INVALID_HANDLE_VALUE;  //源文件句柄
	HANDLE hDestFile = INVALID_HANDLE_VALUE; //目标文件句柄
	HANDLE hIOCP = NULL;                     //IOCP
	LPVOID lpAddr = NULL;                     //申请内存地址

	__try
	{
		cout << endl << "开始打开源文件" << endl;
		//源文件
		hSrcFile = CreateFile(
			lpSrc,                                        //源文件
			GENERIC_READ,                                  //读模式
			FILE_SHARE_READ,                              //读共享
			NULL,                                         //安全属性
			OPEN_EXISTING,                                  //文件必须存在
			FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING,//异步 | 不用缓存
			NULL                                          //文件模板为空
		);
		if (INVALID_HANDLE_VALUE == hSrcFile)
		{
			ShowErrMsg("源文件打开错误");
			return -1;
		}

		cout << endl << "开始打开目的文件" << endl;

		//目的文件
		hDestFile = CreateFile(
			lpDest,                                        //目的文件
			GENERIC_WRITE,                                 //写模式
			0,                                               //独占访问
			NULL,                                           //安全属性
			CREATE_ALWAYS,                                   //总是创建
			FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING, //异步 | 不用缓存
			hSrcFile                                       //文件属性同源文件
		);
		if (INVALID_HANDLE_VALUE == hDestFile)
		{
			ShowErrMsg("目的文件打开错误");
			return -2;
		}

		cout << endl << "开始获取文件尺寸" << endl;
		//源文件尺寸
		LARGE_INTEGER liFileSize;
		BOOL bRet = GetFileSizeEx(hSrcFile, &liFileSize);
		if (FALSE == bRet)
		{
			ShowErrMsg("获取源文件尺寸失败");
			return -3;
		}

		cout << endl << "开始用源文件尺寸设置目的文件大小" << endl;

		//设置目的文件指针位置为源文件尺寸 并 设置文件尾
		BOOL bRet2 = SetFilePointerEx(hDestFile, liFileSize, NULL, FILE_BEGIN);
		BOOL bRet3 = SetEndOfFile(hDestFile);
		if (FALSE == bRet2 || FALSE == bRet3)
		{
			ShowErrMsg("设置目的文件尺寸失败");
			return -4;
		}

		cout << endl << "开始获取磁盘扇区大小 和 系统信息" << endl;
		SYSTEM_INFO sysInfo = { 0 };
		GetSystemInfo(&sysInfo);
		printf_s("共有%d个CPU\n", sysInfo.dwNumberOfProcessors);
		/*
		SYSTEM_INFO结构体参数说明：
		wProcessorArchitecture: Word;　{处理器的体系结构}
		wReserved: Word;　 {保留}
		dwPageSize: DWORD;　 {分页大小}
		lpMinimumApplicationAddress: Pointer;{最小寻址空间}
		lpMaximumApplicationAddress: Pointer;{最大寻址空间}
		dwActiveProcessorMask: DWORD;　{处理器掩码; 0..31 表示不同的处理器}
		dwNumberOfProcessors: DWORD;　 {处理器数目}
		dwProcessorType: DWORD;　{处理器类型}
		dwAllocationGranularity: DWORD;　{虚拟内存空间的粒度}
		wProcessorLevel: Word;　 {处理器等级}
		wProcessorRevision: Word);　 {处理器版本}
		*/

		DWORD dwBytesPerSector = 0UL;
		bRet = GetDiskFreeSpace(TEXT("D:"), NULL, &dwBytesPerSector, NULL, NULL);
		/*
		BOOL WINAPI GetDiskFreeSpaceW(
			_In_opt_ LPCWSTR lpRootPathName,//路径
			_Out_opt_ LPDWORD lpSectorsPerCluster,//每个簇有多少个扇区
			_Out_opt_ LPDWORD lpBytesPerSector,//每个扇区有多少个字节
			_Out_opt_ LPDWORD lpNumberOfFreeClusters,//可用的簇
			_Out_opt_ LPDWORD lpTotalNumberOfClusters//总的簇
			);
		*/
		if (FALSE == bRet)
		{
			ShowErrMsg("开始获取磁盘扇区大小 错误");
			return -5;
		}

		

		//读 ol结构
		OVERLAPPED ovlpRead;
		ovlpRead.Offset = 0;
		ovlpRead.OffsetHigh = 0;
		ovlpRead.hEvent = NULL;

		//写 ol结构
		OVERLAPPED ovlpWrite;
		ovlpWrite.Offset = 0;
		ovlpWrite.OffsetHigh = 0;
		ovlpWrite.hEvent = NULL;

		//创建IOCP 并和 hFile关联
		hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, sysInfo.dwNumberOfProcessors);
		if (NULL == hIOCP)//新建一个IOCP。
		{
			DWORD dwErr = GetLastError();
			if (ERROR_ALREADY_EXISTS != dwErr)
			{
				ShowErrMsg("创建IOCP 失败");
				return -6;
			}
		}

		hIOCP = CreateIoCompletionPort(hSrcFile, hIOCP, CK_READ, sysInfo.dwNumberOfProcessors);
		hIOCP = CreateIoCompletionPort(hDestFile, hIOCP, CK_WRITE, sysInfo.dwNumberOfProcessors);

		//申请扇区X倍的内存(因为使用了FILE_FLAG_NO_BUFFERING 所以必须为扇区大小的整数倍)
		size_t sizeMAX = dwBytesPerSector * 1024 * 64 * 2; //512K * 64 * 2
		size_t sizeMIN = dwBytesPerSector * 1024 * 64 * 2;

		//申请内存
		lpAddr = VirtualAlloc(NULL, sizeMAX, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		if (NULL == lpAddr)
		{
			ShowErrMsg("申请内存错误");
			return -7;
		}


		//先往IOCP的完成队列插入一个 写完成 项
		//写0字节
		PostQueuedCompletionStatus(
			hIOCP,     //IOCP
			0,           //GetQueuedCompletionStatus取到的传送字节为0(用来触发写完成，第一次是0 所以它会从0开始读)
			CK_WRITE,  //写操作
			&ovlpWrite //写OVERLAPPED
		);//如果不用post 你就得自己开个线程去触发了


		DWORD dwBytesTrans = 0;                                    //传输字节数
		ULONG_PTR ulCompleteKey = 0;                            //完成键
		LPOVERLAPPED lpOverlapped = NULL;                        //OVERLAPPED结构
		BOOL bLastTime = FALSE;                                    //最后一个读操作
		int i = 0;
		int j = 0;
		int nCountZero = 0;                                        //计数 


		/************************************************************************/
		/* 因为前一次只是往IOCP的完成队列插入了一项【写完成】，而并非真的写
		只是让下面的代码从 【读操作】开始，
		执行序列为： 读-写， 读-写， ... ，读-写
		当每个【读操作】完成时：把缓冲区中的数据写入【目的文件】，并更新【源文件】的偏移量


		当每个【写操作】完成时：更新【目的文件】的偏移量，
		同时，因为操作序列是写操作在后，因此写操作完成后，根据更新后的【源文件】的偏移量
		和【源文件】大小做比较，如果大于等于源文件大小，则说明这是最后一次读取操作，则当下一次
		写操作完成时 退出循环。 如果当前【源文件偏移量】没有达到【源文件大小】则再次从【源文件】
		中读取数据进缓冲区，
		/************************************************************************/
		while (TRUE)
		{
			BOOL bRet = GetQueuedCompletionStatus(hIOCP, &dwBytesTrans, &ulCompleteKey, &lpOverlapped, INFINITE);
			if (FALSE == bRet)
			{
				DWORD dwErr = GetLastError();
				if (NULL != lpOverlapped)
				{
					ShowErrMsg("线程函数返回错误， 错误原因:");
					cout << dwErr << endl;
					break;
				} //if
				else
				{
					if (ERROR_TIMEOUT == dwErr)
					{
						ShowErrMsg("等待超时");
					}
					else
					{
						ShowErrMsg("线程函数返回错误， 错误原因2:");
						cout << dwErr << endl;
					}

					continue;
				} //else  

			} //if

			//读操作完成 
			if (ulCompleteKey == CK_READ)//如果获取到是读完成 就该写文件
			{
				cout << endl << "-------------第 " << ++i << " 次读操作完成，开始写文件 ---------------- " << endl;
				WriteFile(hDestFile, lpAddr, sizeMIN, NULL, &ovlpWrite);
				//获取读完成 读了多少字节(已传输字节)
				LARGE_INTEGER liDoneBytes;
				liDoneBytes.QuadPart = dwBytesTrans;

				//ovlpRead.Offset += liDoneBytes.LowPart;
				//ovlpRead.OffsetHigh += liDoneBytes.HighPart;
				//用指针或全局定义的都可以更新
				//更新读文件的偏移，完成后我们需要更新OL结构的偏移
				lpOverlapped->Offset = liDoneBytes.LowPart;
				lpOverlapped->OffsetHigh = liDoneBytes.HighPart;

			} //if

			//写操作完成 
			else if (ulCompleteKey == CK_WRITE)//如果获取到是写完成 就该读文件 //刚才post用来触发写完成 所以下面是读
			{
				//获取写完成 写了多少字节(已传输字节)
				LARGE_INTEGER liDoneBytes;
				liDoneBytes.QuadPart = dwBytesTrans;
				//ovlpWrite.Offset += liDoneBytes.LowPart;
				//ovlpWrite.OffsetHigh += liDoneBytes.HighPart;
				//用指针或全局定义的都可以更新
				//更新写文件的偏移，完成后我们需要更新OL结构的偏移
				lpOverlapped->Offset = liDoneBytes.LowPart;
				lpOverlapped->OffsetHigh = liDoneBytes.HighPart;

				//获取当前读文件的偏移（用来判断写完后该不该再读了）//第一次用来触发时是0
				LARGE_INTEGER liTemp;
				liTemp.LowPart = ovlpRead.Offset;
				liTemp.HighPart = ovlpRead.OffsetHigh;
				//当前读文件偏移小于文件大小 就 继续读 读后会继续触发写
				if (liTemp.QuadPart < liFileSize.QuadPart)
				{
					cout << endl << "*************第 " << ++j << " 次写操作完成，开始读文件 ***************" << endl;
					ReadFile(hSrcFile, lpAddr, sizeMIN, NULL, &ovlpRead);
				}
				else {
					break;
				}
			}

		}

		SetFilePointerEx(hDestFile, liFileSize, NULL, FILE_BEGIN);
		SetEndOfFile(hDestFile);

		cout << endl << " $$$$$$$$$$$$$$$$$$$$$ 操作完成 $$$$$$$$$$$$$$$$$" << endl;

	}
	__finally
	{
		cout << endl << "清理资源" << endl;
		if (INVALID_HANDLE_VALUE != hSrcFile)
			CloseHandle(hSrcFile);
		hSrcFile = INVALID_HANDLE_VALUE;

		if (INVALID_HANDLE_VALUE != hDestFile)
			CloseHandle(hDestFile);
		hDestFile = INVALID_HANDLE_VALUE;

		if (NULL != lpAddr)
			VirtualFree(lpAddr, 0, MEM_RELEASE | MEM_DECOMMIT);
		lpAddr = NULL;
	}



	cout << endl << endl;
	return 0;
}




void ShowErrMsg(LPCSTR lpMsg) { cout << endl << "Some error happened : " << lpMsg << "\n"; }
