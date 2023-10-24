#include "stdafx.h"
#include <cstring>
#include <string>

using namespace std;
class StStudentInfo
{
public:
    StStudentInfo()
    {
        pszAddress = new char[1024];
        strName = "李四";
    };
    ~StStudentInfo()
    {
        delete pszAddress;
    }

public:
    int nlD;
    string strName;
    char *pszAddress;
};
StStudentInfo *CopyStudentInfo(StStudentInfo *pInfoA)
{
    StStudentInfo *pInfoB = new StStudentInfo();
    memset(pInfoB, 0, sizeof(StStudentInfo));
    *pInfoB = *pInfoA;
    return pInfoB;
}
int _tmain(int argc, _TCHAR *argvD)
{
    StStudentInfo *pInfoA = new StStudentInfo;
    if (pInfoA == NULL)
        return 0;
    pInfoA->nlD = 100;
    pInfoA->strName = "张三";
    memcpy(pInfoA->pszAddress, "中国福建福州晋安区某某地址栋号" sizeof(pInfoA->pszAddress));
    StStudentInfo *pInfoB = CopyStudentInfo(pInfoA);
    printf("Student B ID =%s", pInfoB->nlD);
    printf("Student B name = %s", pInfoB->strName.c_str());
    printf("Student B Address= %s", pInfoB->pszAddress);
    delete pInfoA;
    delete pInfoB;
    return 0;
}
