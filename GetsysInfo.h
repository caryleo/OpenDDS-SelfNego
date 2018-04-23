#ifndef _H_GETSYSINFO  
#define _H_GETSYSINFO  


#pragma once  


#include <afxcoll.h>
#include <afxtempl.h>
#include <atltypes.h>
#include <string>

struct interfaces {
	char name[10][100];
	int band[10];
};

class GetSysInfo
{
public:
	GetSysInfo(void);
	~GetSysInfo(void);

public:
				   /***********��ȡ������Ŀ������***********/
	//int  GetInterFaceCount(struct interfaces *strs);
	int  GetInterFaceCount(long *band);
	void GetInterFaceName(CString &InterfaceName, int pNum);
	
private:
	CStringList Interfaces;                       //������������������  
	CList < DWORD, DWORD &>       Bandwidths;   //�������Ĵ���  
	CList < DWORD, DWORD &>       TotalTraffics;    //��������������  
};

#endif