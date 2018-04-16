#ifndef _H_GETSYSINFO  
#define _H_GETSYSINFO  

#include <atlstr.h>
//#include <afxcoll.h>
//#include <afxtempl.h>
#include <atltypes.h>

class GetSysInfo
{
public:
	GetSysInfo(void);
	~GetSysInfo(void);

public:
	/********获取操作系统版本，Service pack版本、系统类型************/
	void GetOSVersion(CString &strOSVersion, CString &strServiceVersion);
	BOOL IsWow64();//判断是否为64位操作系统  

				   /***********获取网卡数目和名字***********/
	int  GetInterFaceCount();
	void GetInterFaceName(CString &InterfaceName, int pNum);

	/***获取物理内存和虚拟内存大小***/
	void GetMemoryInfo(CString &dwTotalPhys, CString &dwTotalVirtual);

	/****获取CPU名称、内核数目、主频*******/
	void GetCpuInfo(CString &chProcessorName, CString &chProcessorType, DWORD &dwNum, DWORD &dwMaxClockSpeed);

	/****获取硬盘信息****/
	void GetDiskInfo(DWORD &dwNum, CString chDriveInfo[]);

	/****获取显卡信息*****/
	void GetDisplayCardInfo(DWORD &dwNum, CString chCardName[]);
private:
	CStringList Interfaces;                       //保存所有网卡的名字  
	CList < DWORD, DWORD &>       Bandwidths;   //各网卡的带宽  
	CList < DWORD, DWORD &>       TotalTraffics;    //各网卡的总流量  
};

#endif