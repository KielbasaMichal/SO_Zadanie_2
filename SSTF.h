#pragma once
#include "head.h"
#include "AccessTask.h"
#include "HardDrive.h"

class SSTF
{
private:
	HardDrive hardDrive;
	std::map<int, AccessTask> map;
	std::vector<AccessTask> waitList;
	int distance = 0;

public:
	SSTF(HardDrive hardDrive, std::vector<AccessTask> tab);
	~SSTF();

	void run();
	void statistic();
};

