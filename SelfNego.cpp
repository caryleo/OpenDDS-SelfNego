#include "SelfNego.h"

SelfNego::SelfNego(void)
{
    isReader = 0;
}

SelfNego::~SelfNego(void)
{

}

SelfNego SelfNego::getInstance()
{
    if(instance == nullptr)
    {
        instance = new SelfNego();
    }
    return *instance;
}

void SelfNego::getNetState()
{
    netState = new NetState();
    netState->test(ip);
}

void SelfNego::getQoS()
{
    double delay = netState->getDelay();
    double packetloss = netState->getPacketLoss();
    if (delay > DELAY_THRESHOLD_1 && delay <= DELAY_THRESHOLD_2)
    {
        if (packetloss > PACKETLOSS_THRESHOLD_1 && packetloss <= PACKETLOSS_THRESHOLD_2)
        {
            if  (isReader == 1)
            {
                reader.history.kind = KEEP_ALL_HISTORY_QOS;
            }
            else if (isReader == 2)
            {
                writer.reliability.kind = RELIABLE_RELIABILITY_QOS;
                writer.history.kind = KEEP_ALL_HISTORY_QOS;
            }
        }
        else if (packetloss > PACKETLOSS_THRESHOLD_2 && packetloss <= PACKETLOSS_THRESHOLD_3)
        {
            if  (isReader == 1)
            {
                
            }
            else if (isReader == 2)
            {

            }
        }
        else
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
    }
    else if (delay > DELAY_THRESHOLD_2 && delay <= DELAY_THRESHOLD_3)
    {
        if (packetloss > PACKETLOSS_THRESHOLD_1 && packetloss <= PACKETLOSS_THRESHOLD_2)
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
        else if (packetloss > PACKETLOSS_THRESHOLD_2 && packetloss <= PACKETLOSS_THRESHOLD_3)
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
        else
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
    }
    else
    {
        if (packetloss > PACKETLOSS_THRESHOLD_1 && packetloss <= PACKETLOSS_THRESHOLD_2)
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
        else if (packetloss > PACKETLOSS_THRESHOLD_2 && packetloss <= PACKETLOSS_THRESHOLD_3)
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
        else
        {
            if  (isReader == 1)
            {

            }
            else if (isReader == 2)
            {

            }
        }
    }

DDS::DataReaderQos SelfNego::makeReaderQos(char input[])
{
    DDS::DataReaderQoS ans;
    ans = DATAREADER_QOS_DEFAULT;
    isReader = 1;
    getNetState();
    getQoS();
    return ans;
}

DDS::DataWriterQos SelfNego::makeWriterQos(char input[])
{
    DDS::DataWriterQos ans;
    ans = DATAWRITER_QOS_DEFAULT;
    isReader = 2;
    getNetState();
    getQos();
    return ans;
}
