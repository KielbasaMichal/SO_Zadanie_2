#pragma once
#include "head.h"
#include "HardDrive.h"
#include "AccessTask.h"

class FCFS
{
private:
	HardDrive hardDrive;
	std::queue<AccessTask> queue;
	std::vector<AccessTask> waitList;
	int distance = 0;

public:
	FCFS(HardDrive hardDrive, std::vector<AccessTask> tab);
	~FCFS();

	void run();
	void statistic();
};

