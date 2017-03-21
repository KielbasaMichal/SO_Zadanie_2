#include "RealTimeTask.h"



RealTimeTask::RealTimeTask(int block, int deadline) : AccessTask(block)
{
	RealTimeTask::deadline = deadline;
}

RealTimeTask::RealTimeTask(int block, int time, int deadline) : AccessTask(block, time)
{
	RealTimeTask::deadline = deadline;
}


RealTimeTask::~RealTimeTask()
{
}

int RealTimeTask::getDeadline() const
{
	return deadline;
}

bool operator<(const RealTimeTask & a, const RealTimeTask & b)
{
	return a.getDeadline() > b.getDeadline();
}
