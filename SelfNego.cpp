#include "SelfNego.h"


SelfNego* SelfNego::s_instance = nullptr;

SelfNego::SelfNego(void)
{
    isReader = 0;
}

SelfNego::~SelfNego(void)
{

}

void SelfNego::getNetState()
{
    netState = new NetState();
    netState->test(ip);
}

int SelfNego::getQoS()
{
	double delay = netState->getDelay();
	double packetloss = netState->getPacketLoss();
	if (delay > DELAY_THRESHOLD_1 && delay <= DELAY_THRESHOLD_2)
	{
		if (packetloss > PACKETLOSS_THRESHOLD_1 && packetloss <= PACKETLOSS_THRESHOLD_2)
		{
			if (isReader == 1)
			{
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
			}
			else if (isReader == 2)
			{
				reader.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
			}
		}
		else if (packetloss > PACKETLOSS_THRESHOLD_2 && packetloss <= PACKETLOSS_THRESHOLD_3)
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				reader.history.depth = 10;
				reader.deadline.period.sec = 150;
				reader.deadline.period.nanosec = 0;
				reader.time_based_filter.minimum_separation.sec = 20;
				reader.time_based_filter.minimum_separation.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::BEST_EFFORT_RELIABILITY_QOS;
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				writer.history.depth = 10;
				writer.deadline.period.sec = 100;
				writer.deadline.period.nanosec = 0;
				writer.lifespan.duration.sec = 50;
				writer.lifespan.duration.nanosec = 0;
			}
		}
		else
		{
			if (isReader == 1)
			{
				reader.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				reader.deadline.period.sec = 250;
				reader.deadline.period.nanosec = 0;
				reader.time_based_filter.minimum_separation.sec = 50;
				reader.time_based_filter.minimum_separation.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				writer.reliability.max_blocking_time.sec = 10;
				writer.reliability.max_blocking_time.nanosec = 0;
				writer.resource_limits.max_samples_per_instance = 100;
				writer.deadline.period.sec = 200;
				writer.deadline.period.nanosec = 0;
				writer.lifespan.duration.sec = 20;
				writer.lifespan.duration.nanosec = 0;
			}
		}
	}
	else if (delay > DELAY_THRESHOLD_2 && delay <= DELAY_THRESHOLD_3)
	{
		if (packetloss > PACKETLOSS_THRESHOLD_1 && packetloss <= PACKETLOSS_THRESHOLD_2)
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
				reader.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				reader.reliability.max_blocking_time.sec = 10;
				reader.reliability.max_blocking_time.nanosec = 0;
				reader.resource_limits.max_samples_per_instance = 100;
				reader.deadline.period.sec = 150;
				reader.deadline.period.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				writer.reliability.max_blocking_time.sec = 10;
				writer.reliability.max_blocking_time.nanosec = 0;
				writer.resource_limits.max_samples_per_instance = 100;
				writer.deadline.period.sec = 100;
				writer.deadline.period.nanosec = 0;
			}
		}
		else if (packetloss > PACKETLOSS_THRESHOLD_2 && packetloss <= PACKETLOSS_THRESHOLD_3)
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				reader.history.depth = 10;
				reader.deadline.period.sec = 200;
				reader.deadline.period.nanosec = 0;
				reader.time_based_filter.minimum_separation.sec = 20;
				reader.time_based_filter.minimum_separation.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				writer.history.depth = 10;
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::BEST_EFFORT_RELIABILITY_QOS;
				writer.deadline.period.sec = 150;
				writer.deadline.period.nanosec = 0;
				writer.lifespan.duration.sec = 100;
				writer.lifespan.duration.nanosec = 0;
			}
		}
		else
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
				reader.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				reader.reliability.max_blocking_time.sec = 10;
				reader.reliability.max_blocking_time.nanosec = 0;
				reader.resource_limits.max_samples_per_instance = 100;
				reader.deadline.period.sec = 150;
				reader.deadline.period.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				writer.reliability.max_blocking_time.sec = 10;
				writer.reliability.max_blocking_time.nanosec = 0;
				writer.resource_limits.max_samples_per_instance = 100;
				writer.deadline.period.sec = 100;
				writer.deadline.period.nanosec = 0;
			}
		}
	}
	else
	{
		if (packetloss > PACKETLOSS_THRESHOLD_1 && packetloss <= PACKETLOSS_THRESHOLD_2)
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				reader.history.depth = 10;
				reader.deadline.period.sec = 150;
				reader.deadline.period.nanosec = 0;
				reader.time_based_filter.minimum_separation.sec = 10;
				reader.time_based_filter.minimum_separation.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				writer.reliability.max_blocking_time.sec = 10;
				writer.reliability.max_blocking_time.nanosec = 0;
				writer.resource_limits.max_samples_per_instance = 100;
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				writer.history.depth = 10;
				writer.deadline.period.sec = 100;
				writer.deadline.period.nanosec = 0;
				writer.lifespan.duration.sec = 50;
				writer.lifespan.duration.nanosec = 0;
			}
		}
		else if (packetloss > PACKETLOSS_THRESHOLD_2 && packetloss <= PACKETLOSS_THRESHOLD_3)
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				reader.history.depth = 10;
				reader.deadline.period.sec = 250;
				reader.deadline.period.nanosec = 0;
				reader.time_based_filter.minimum_separation.sec = 50;
				reader.time_based_filter.minimum_separation.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
				writer.history.depth = 10;
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::BEST_EFFORT_RELIABILITY_QOS;
				writer.deadline.period.sec = 200;
				writer.deadline.period.nanosec = 0;
				writer.lifespan.duration.sec = 100;
				writer.lifespan.duration.nanosec = 0;
			}
		}
		else
		{
			if (isReader == 1)
			{
				reader.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
				reader.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				reader.reliability.max_blocking_time.sec = 10;
				reader.reliability.max_blocking_time.nanosec = 0;
				reader.resource_limits.max_samples_per_instance = 100;
				reader.deadline.period.sec = 150;
				reader.deadline.period.nanosec = 0;
			}
			else if (isReader == 2)
			{
				writer.history.kind = DDS::HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
				writer.reliability.kind = DDS::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
				writer.reliability.max_blocking_time.sec = 10;
				writer.reliability.max_blocking_time.nanosec = 0;
				writer.resource_limits.max_samples_per_instance = 100;
				writer.deadline.period.sec = 100;
				writer.deadline.period.nanosec = 0;
			}
			return 1;
		}
	}
	return 0;
}

DDS::DataReaderQos SelfNego::getReaderQos(char input[], int &isUdp)
{
	int len = strlen(input);
	int j = 0;
	for (int i = 10; i < 21; i++)
	{
		ip[j++] = input[i];
	}
	for (int i = 11; i < 20; i++)
	{
		ip[i] = 0;
	}
	std::string str(ip);
	std::cout << "IP: " << str << std::endl;
	DDS::DataReaderQos ans;
	ans = DATAREADER_QOS_DEFAULT;
	isReader = 1;
	getNetState();
	std::cout << "Delay: " << netState->getDelay() << std::endl;
	std::cout << "Packetloss: " << netState->getPacketLoss() << std::endl;
	isUdp = getQoS();
	return ans;
}

DDS::DataWriterQos SelfNego::getWriterQos(char input[], int &isUdp)
{
	int len = strlen(input);
	int j = 0;
	for (int i = 10; i < 21; i++)
	{
		ip[j++] = input[i];
	}
	for (int i = 11; i < 20; i++)
	{
		ip[i] = 0;
	}
	printf("IP: %s\n", ip);
    DDS::DataWriterQos ans;
    ans = DATAWRITER_QOS_DEFAULT;
    isReader = 2;
    getNetState();
	std::cout << "Delay: " << netState->getDelay() << std::endl;
	std::cout << "Packetloss: " << netState->getPacketLoss() << std::endl;
	isUdp = getQoS();
    return ans;
}
