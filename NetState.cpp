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

void NetState::testBandwidth()
{

}

void NetState::testRatio()
{

}

void NetState::testDelay()
{

}

void NetState::testThroughtput()
{

}

void NetState::testPacketLoss()
{

}

void NetState::setBandWidth(double input)
{
    bandWidth = input;
}

double NetState::getBandWidth()
{
    return bandWidth;
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