#include "AccessTask.h"

AccessTask::AccessTask()
{
	accessBlock = 0;
	delay = 0;
}

AccessTask::AccessTask(int block)
{
	accessBlock = block;
	delay = 0;
}

AccessTask::AccessTask(int block, int time)
{
	accessBlock = block;
	delay = time;
}

AccessTask::~AccessTask()
{
}


int AccessTask::getBlock()
{
	return accessBlock;
}

int AccessTask::getDelay()
{
	return delay;
}
