#pragma once


#include "GetsysInfo.h"
#include "Ping.h"
#include <cstring>
#include <afxtempl.h>
#include <dds\DdsDcpsInfrastructureC.h>
#include <dds\DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
#include <dds\DCPS\StaticIncludes.h>
#include <dds\DCPS\Service_Participant.h>
#include <dds\DCPS\Marked_Default_Qos.h>


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
