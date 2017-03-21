#pragma once
#include "AccessTask.h"
class RealTimeTask : public AccessTask
{
private:
	int deadline;
public:
	RealTimeTask(int block, int deadline);
	RealTimeTask(int block, int time, int deadline);
	~RealTimeTask();

	int getDeadline() const;

	friend bool operator<(const RealTimeTask &a, const RealTimeTask &b);
};

