#ifndef SELFNEGO_H_
#define SELFNEGO_H_

#include "NetState.h"

class SelfNego
{
  public:
    SelfNego(void);
    ~SelfNego(void);

    static SelfNego* getInstance();
    void make();
  private:
    static SelfNego* instance;
    //TODO: 负责存储传入的默认QoS实例。

    void setProfile(/***/);
    NetState* getNetState();
    /***/void getQoS();
};

#endif