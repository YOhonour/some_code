// #include <iostream>
// #include <errhandlingapi.h>
// #include<windows.h>
// #include<tchar.h>

// using namespace std;

// void DisplayErrorText(DWORD dwLastError);
//  //完成键
// #define CK_READ  1
// #define CK_WRITE 2
// #define RTN_OK 0
// #define RTN_USAGE 1
// #define RTN_ERROR 13

// int main() {
//     LPCTSTR lpSrc = TEXT("\\data\\test.mp3");
// 	LPCTSTR lpDest = TEXT("\\data\\test_copy.mp3");

//     HANDLE hFile = CreateFile(
//         lpSrc,
//         GENERIC_READ, 
//         FILE_SHARE_READ, 
//         NULL,
//         OPEN_EXISTING,
//         FILE_FLAG_OVERLAPPED,
//         NULL
//     );
//     if (INVALID_HANDLE_VALUE == hFile)
// 	{
// 		DWORD err = GetLastError();
//         DisplayErrorText(err);
// 		return -1;
// 	}
//     cout << endl << "开始打开目的文件" << endl;
//     HANDLE hDestFile = CreateFile(
// 			lpDest,                                        //目的文件
// 			GENERIC_WRITE,                                 //写模式
// 			0,                                               //独占访问
// 			NULL,                                           //安全属性
// 			CREATE_ALWAYS,                                   //总是创建
// 			FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING, //异步 | 不用缓存
// 			hFile                                       //文件属性同源文件
// 		);

//     if (INVALID_HANDLE_VALUE == hDestFile)
// 	{
// 		DWORD err = GetLastError();
//         DisplayErrorText(err);
// 		return -1;
// 	}

//     cout << endl << "开始获取文件尺寸" << endl;
// 	//源文件尺寸
// 	LARGE_INTEGER liFileSize;
// 	BOOL bRet = GetFileSizeEx(hFile, &liFileSize);
//     if (FALSE == bRet)
// 	{
// 		DWORD err = GetLastError();
//         DisplayErrorText(err);
// 		return -3;
// 	}
//     cout << endl << "开始用源文件尺寸设置目的文件大小" << endl;
//     BOOL bRet2 = SetFilePointerEx(hDestFile, liFileSize, NULL, FILE_BEGIN);
// 	BOOL bRet3 = SetEndOfFile(hDestFile);
// 	if (FALSE == bRet2 || FALSE == bRet3)
// 	{
// 		DWORD err = GetLastError();
//         DisplayErrorText(err);
// 		return -4;
// 	}
//     cout << endl << "开始获取磁盘扇区大小 和 系统信息" << endl;
//     SYSTEM_INFO sysInfo = { 0 };
// 	GetSystemInfo(&sysInfo);
// 	printf_s("共有%d个CPU\n", sysInfo.dwNumberOfProcessors);
//     DWORD dwBytesPerSector = 0UL;
// 	bRet = GetDiskFreeSpace(TEXT("D:"), NULL, &dwBytesPerSector, NULL, NULL);

//     if (FALSE == bRet)
// 	{
// 		DWORD err = GetLastError();
//         DisplayErrorText(err);
// 		return -5;
// 	}

//     OVERLAPPED ovlpRead;
// 	ovlpRead.Offset = 0;
// 	ovlpRead.OffsetHigh = 0;
// 	ovlpRead.hEvent = NULL;

// 	//写 ol结构
// 	OVERLAPPED ovlpWrite;
// 	ovlpWrite.Offset = 0;
// 	ovlpWrite.OffsetHigh = 0;
// 	ovlpWrite.hEvent = NULL;
//     HANDLE hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, sysInfo.dwNumberOfProcessors);
// 	if (NULL == hIOCP)//新建一个IOCP。
// 	{
// 		DWORD dwErr = GetLastError();
// 		if (ERROR_ALREADY_EXISTS != dwErr)
// 		{
// 			DWORD err = GetLastError();
//             DisplayErrorText(err);
// 			return -6;
// 		}
// 	}


//     hIOCP = CreateIoCompletionPort(hSrcFile, hIOCP, CK_READ, sysInfo.dwNumberOfProcessors);
// 	hIOCP = CreateIoCompletionPort(hDestFile, hIOCP, CK_WRITE, sysInfo.dwNumberOfProcessors);






//     return 0;
// }

// void DisplayErrorText(DWORD dwLastError)
// {
// 	HMODULE hModule = NULL; //default to system source
// 	LPSTR MessageBuffer;
// 	DWORD dwBufferLength;
 
// 	DWORD dwFormatFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER |
// 		FORMAT_MESSAGE_IGNORE_INSERTS |
// 		FORMAT_MESSAGE_FROM_SYSTEM;
 
// 	//
// 	// If dwLastError is in the network range, 
// 	// load the message source.
// 	//
 
// 	if (dwLastError >= NERR_BASE && dwLastError <= MAX_NERR)
// 		{
// 			hModule = LoadLibraryEx(
// 				TEXT("netmsg.dll"),
// 				NULL,
// 				LOAD_LIBRARY_AS_DATAFILE
// 				);
// 			if(hModule !=NULL)
// 				dwFormatFlags != FORMAT_MESSAGE_FROM_HMODULE;
// 		}
 
// 	//
// 	// Call FormatMessage() to allow for message
// 	// text to be acquired from the system
// 	// or from the supplied module handle.
// 	//
 
// 	if(dwBufferLength = FormatMessageA(
// 		dwFormatFlags,
// 		hModule, // module to get message from (NULL == system)
// 		dwLastError,
// 		MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT), // default language
// 		(LPSTR) &MessageBuffer,
// 		0,
// 		NULL))
// 		{
// 			DWORD dwBytesWritten;
 
// 			//
// 			// Output message string on stderr.
// 			//
// 			WriteFile(
// 				GetStdHandle(STD_ERROR_HANDLE),
// 				MessageBuffer,
// 				dwBufferLength,
// 				&dwBytesWritten,
// 				NULL
// 				);
 
// 			//
// 			// Free the buffer allocated by the system
// 			//
// 			LocalFree(MessageBuffer);
// 		}
 
// 	// 
// 	// If we loaded a message source , unload it.
// 	//
// 	if(hModule != NULL)
// 		FreeLibrary(hModule);
// }
