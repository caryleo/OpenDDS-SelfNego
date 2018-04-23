#pragma once

#include "stdafx.h"
#include <cstring>
#include <afxtempl.h>
#include "GetsysInfo.h"
#include "Ping.h"


class NetState {
public:
	NetState();
	~NetState();
	void test(char ip[]);
	void setBandWidth(double input);
	double getBandWidth();
	/*void setThroughput(double input);
	double getThroughput();
	void setRatio(double input);
	double getRatio();*/
	void setDelay(double input);
	double getDelay();
	void setPacketLoss(double input);
	double getPacketLoss();

private:
	double bandWidth;  //������λbps
	//double throughput; //����������λbps
	//double ratio;      //������
	double delay;      //ʱ�ӣ���λms
	double packetLoss; //������
};
