#ifndef SELFNEGO_H_
#define SELFNEGO_H_

#include "NetState.h"

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
    DDS::DataReaderQos reader;
    DDS::DataReaderQos writer;
    char ip[20];
};

#endif