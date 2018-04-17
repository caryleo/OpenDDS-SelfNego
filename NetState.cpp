#include "NetState.h"

NetState::NetState(void)
{
    bandWidth = 0;
    throuhgput = 0;
    ratio = 0;
    delay = 0;
    packetLoss = 0;
}

NetState::~NetState(void)
{
}

//void NetState::testBandwidth()
//{
//
//}
//
//void NetState::testRatio()
//{
//
//}
//
//void NetState::testDelay()
//{
//
//}
//
//void NetState::testThroughtput()
//{
//
//}
//
//void NetState::testPacketLoss()
//{
//
//}
void NetState::test(char ip[])
{
	long bands[10];
	GetSysInfo info;
	int num = info.GetInterFaceCount(bands);
	//printf("%d\n", num);
	int best = 0;
	for (int i = 0; i < num; i++) {
		if (bands[i] > bands[best])
			best = i;
	}
	setBandWidth(bands[best]);

	CPing objPing;

	char *szDestIP;
	char defaultip[100] = "10.4.21.55";
	szDestIP = ip;
	if (ip == NULL)
		szDestIP = defaultip;
	PingReply reply;

	//printf("Pinging %s with %d bytes of data:\n", szDestIP, DEF_PACKET_SIZE);
	double times = 0;
	int rolls = 100;
	int faildpackegs = 0;
	for (int i = 0; i < rolls; i++)
	{
		objPing.Ping(szDestIP, &reply, (DWORD)10);
		if (reply.m_dwRoundTripTime > 50) {
			faildpackegs++;
			continue;
		}
		times += reply.m_dwRoundTripTime;
		printf("\r[*]Network Testing...%d%%", i);
		//printf("Reply from %s: bytes=%ld time=%ldms TTL=%ld\n", szDestIP, reply.m_dwBytes, reply.m_dwRoundTripTime, reply.m_dwTTL);
		//Sleep(500);
	}
	setDelay(times / (double)(rolls - faildpackegs));
	setPacketLoss(((double)faildpackegs / rolls) * 100.0);
	setThrouhgput(DEF_PACKET_SIZE / avrtime);
	setRatio(throuhgpu / bandWidth);
}

void NetState::setBandWidth(double input)
{
    bandWidth = input;
}

double NetState::getBandWidth()
{
    return bandWidth;
}

void NetState::setThroughput(double input)
{
    throuhgput = input;
}

double NetState::getThroughput()
{
    return throuhgput;
}

void NetState::setRatio(double input)
{
    ratio = input;
}

double NetState::getRatio()
{
    return ratio;
}

void NetState::setDelay(double input)
{
    delay = input;
}

double NetState::getDelay()
{
    return delay;
}

void NetState::setPacketLoss(double input)
{
    packetLoss = input;
}

double NetState::getPacketLoss()
{
    return packetLoss;
}
