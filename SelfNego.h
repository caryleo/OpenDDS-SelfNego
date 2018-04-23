#ifndef SELFNEGO_H_
#define SELFNEGO_H_

#include "NetState.h"

//所有的阈值都在这里定义
#define DELAY_THRESHOLD_1 0
#define DELAY_THRESHOLD_2 100
#define DELAY_THRESHOLD_3 200
#define	PACKETLOSS_THRESHOLD_1 0
#define	PACKETLOSS_THRESHOLD_2 1
#define	PACKETLOSS_THRESHOLD_3 5

class SelfNego
{
  public:
    SelfNego(void);
    ~SelfNego(void);

    static SelfNego getInstance();
    void getNetState();
    void getQoS();
    DDS::DataReaderQos makeReaderQos(char input[]);
    DDS::DataWriterQos makeWriterQos(char input[]);
    
  private:
    static SelfNego *instance;
    NetState *netState;
    DDS::DataReaderQos reader;  //1
    DDS::DataReaderQos writer;  //2
    int isReader;
    char ip[20];
};

#endif