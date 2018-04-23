#ifndef SELFNEGO_H_
#define SELFNEGO_H_

#include "NetState.h"

class SelfNego
{
  public:
    SelfNego(void);
    ~SelfNego(void);

    static SelfNego getInstance();
    void setProfile(/***/);
    NetState getNetState();
    /***/void getQoS();
    make

};

#endif