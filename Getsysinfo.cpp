#include "GetsysInfo.h"  
#include <atlbase.h>  
#include <atlstr.h>
#include "float.h"  
#include "winperf.h"  

GetSysInfo::GetSysInfo(void)
{
}

GetSysInfo::~GetSysInfo(void)
{
}


//int GetSysInfo::GetInterFaceCount(struct interfaces *strs)
int GetSysInfo::GetInterFaceCount(long *band) {
	/*CGetNetData pNet;
	DWORD pCount = pNet.GetNetworkInterfacesCount();
	return pCount;*/


	try
	{
#define DEFAULT_BUFFER_SIZE 40960L  

		unsigned char *data = (unsigned char*)malloc(DEFAULT_BUFFER_SIZE);
		DWORD type;
		DWORD size = DEFAULT_BUFFER_SIZE;
		DWORD ret;

		char s_key[4096];
		sprintf_s(s_key, 4096, "510");
		//RegQueryValueEx�Ĺ̶����ø�ʽ          
		CString str(s_key);

		//���RegQueryValueEx����ִ��ʧ�������ѭ��  
		while ((ret = RegQueryValueEx(HKEY_PERFORMANCE_DATA, str, 0, &type, data, &size)) != ERROR_SUCCESS)
		{
			Sleep(10);
			//���RegQueryValueEx�ķ���ֵΪERROR_MORE_DATA(������ڴ���data̫С����������RegQueryValueEx���ص�����)  
			if (ret == ERROR_MORE_DATA)
			{
				Sleep(10);
				size += DEFAULT_BUFFER_SIZE;
				data = (unsigned char*)realloc(data, size);//���·����㹻����ڴ�  

				ret = RegQueryValueEx(HKEY_PERFORMANCE_DATA, str, 0, &type, data, &size);//����ִ��RegQueryValueEx����  
			}
			//���RegQueryValueEx����ֵ�Ծ�δ�ɹ���������.....(ע���ڴ�й¶��free������~~~)��  
			//���if��֤�����whileֻ�ܽ���һ��~~~������ѭ��  
			if (ret != ERROR_SUCCESS)
			{
				if (NULL != data)
				{
					free(data);
					data = NULL;
				}
				return 0;//0���ӿ�  
			}
		}

		//����ִ�гɹ�֮����ǶԷ��ص�data�ڴ������ݵĽ����ˣ��������ȥ�鿴MSDN�й�RegQueryValueEx�����������ݽṹ��˵��  
		//�õ����ݿ�       
		PERF_DATA_BLOCK  *dataBlockPtr = (PERF_DATA_BLOCK *)data;
		//�õ���һ������  
		PERF_OBJECT_TYPE *objectPtr = (PERF_OBJECT_TYPE *)((BYTE *)dataBlockPtr + dataBlockPtr->HeaderLength);

		for (int a = 0; a<(int)dataBlockPtr->NumObjectTypes; a++)
		{
			char nameBuffer[255] = { 0 };
			if (objectPtr->ObjectNameTitleIndex == 510)
			{
				DWORD processIdOffset = ULONG_MAX;
				PERF_COUNTER_DEFINITION *counterPtr = (PERF_COUNTER_DEFINITION *)((BYTE *)objectPtr + objectPtr->HeaderLength);

				for (int b = 0; b<(int)objectPtr->NumCounters; b++)
				{
					if (counterPtr->CounterNameTitleIndex == 520)
						processIdOffset = counterPtr->CounterOffset;

					counterPtr = (PERF_COUNTER_DEFINITION *)((BYTE *)counterPtr + counterPtr->ByteLength);
				}

				if (processIdOffset == ULONG_MAX) {
					if (data != NULL)
					{
						free(data);
						data = NULL;
					}
					return 0;
				}

				PERF_INSTANCE_DEFINITION *instancePtr = (PERF_INSTANCE_DEFINITION *)((BYTE *)objectPtr + objectPtr->DefinitionLength);

				for (int b = 0; b<objectPtr->NumInstances; b++)
				{
					wchar_t *namePtr = (wchar_t *)((BYTE *)instancePtr + instancePtr->NameOffset);
					PERF_COUNTER_BLOCK *counterBlockPtr = (PERF_COUNTER_BLOCK *)((BYTE *)instancePtr + instancePtr->ByteLength);

					char pName[256] = { 0 };
					WideCharToMultiByte(CP_ACP, 0, namePtr, -1, pName, sizeof(nameBuffer), 0, 0);

					DWORD bandwith = *((DWORD *)((BYTE *)counterBlockPtr + processIdOffset));
					DWORD tottraff = 0;

					/*printf("%s\n", pName);
					printf("%ld\n", bandwith);
					printf("***************************************************");
					strcmp(pName, strs->name[b]);
					strs->band[b] = bandwith;
					printf("%s\n", pName);
					printf("%ld\n", bandwith);
					printf("***************************************************");*/
					band[b] = bandwith;
					Interfaces.AddTail(CString(pName)); //������������  
					Bandwidths.AddTail(bandwith);       //����  
					TotalTraffics.AddTail(tottraff);    // ������ʼ��Ϊ0  

					PERF_COUNTER_BLOCK  *pCtrBlk = (PERF_COUNTER_BLOCK *)((BYTE *)instancePtr + instancePtr->ByteLength);


					instancePtr = (PERF_INSTANCE_DEFINITION *)((BYTE *)instancePtr + instancePtr->ByteLength + pCtrBlk->ByteLength);
				}
			}
			objectPtr = (PERF_OBJECT_TYPE *)((BYTE *)objectPtr + objectPtr->TotalByteLength);
		}
		if (data != NULL)
		{
			free(data);
			data = NULL;
		}
	}
	catch (...)
	{
		return 0;
	}
	return Interfaces.GetCount();
}

void GetSysInfo::GetInterFaceName(CString &InterfaceName, int pNum)
{
	/*CGetNetData pNet;
	pNet.GetNetworkInterfaceName(&InterfaceName,pNum);*/

	POSITION pos = Interfaces.FindIndex(pNum);
	if (pos == NULL)
		return;

	InterfaceName = Interfaces.GetAt(pos);
	pos = Bandwidths.FindIndex(pNum);
	if (pos == NULL)
		return;
	DWORD dwBandwidth = Bandwidths.GetAt(pos);

	CString str;
	str.Format(_T("%d"), dwBandwidth);

	InterfaceName = InterfaceName + str;
}