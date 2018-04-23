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
	double bandWidth;  //带宽，单位bps
	//double throughput; //吞吐量，单位bps
	//double ratio;      //利用率
	double delay;      //时延，单位ms
	double packetLoss; //丢包率
};
