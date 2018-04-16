#ifndef NETSTATE_H_
#define NETSTATE_H_

#pragma once

class NetState
{
  public:
    NetState(void);
    ~NetState(void);

    void testBandwidth();   //测试得到带宽
    void testThroughtput(); //测试得到吞吐量
    void testRatio();       //测试得到利用率
    void testDelay();       //测试得到时延
    void testPacketLoss();  //测试得到丢包率

    void setBandWidth(double input);
    double getBandWidth();
    void setThroughput(double input);
    double getThroughput();
    void setRatio(double input);
    double getRatio();
    void setDelay(double input);
    double getDelay();
    void setPacketLoss(double input);
    double getPacketLoss();

  private:
    double bandWidth;  //带宽，单位bps
    double throuhgput; //吞吐量，单位bps
    double ratio;      //利用率
    double delay;      //时延，单位ms
    double packetLoss; //丢包率
};

#endif