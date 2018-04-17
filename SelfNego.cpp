#include "SelfNego.h"

SelfNego::SelfNego(void)
{

}

SelfNego::~SelfNego(void)
{

}

SelfNego* SelfNego::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SelfNego();
    }
    return instance;
}

void SelfNego::make()
{

}

void SelfNego::setProfile()
{

}

NetState* SelfNego::getNetState()
{
    NetState* netState = new NetState();
    return netState;
}

void SelfNego::getQoS()
{

}
