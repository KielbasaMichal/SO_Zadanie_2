#pragma once
#include "HardDrive.h"
#include "RealTimeTask.h"

class EDF
{
private:
	HardDrive hardDrive;
	std::priority_queue<RealTimeTask> queue;
	std::vector<RealTimeTask> waitList;
	int distance = 0;
public:
	EDF(HardDrive hardDrive, std::vector<RealTimeTask> tab);
	~EDF();

	void run();
	void statistic();
};

