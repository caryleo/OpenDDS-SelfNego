#include "SelfNego.h"

SelfNego::SelfNego(void)
{

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
