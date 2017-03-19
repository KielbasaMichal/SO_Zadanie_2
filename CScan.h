#pragma once
#include "head.h"
#include "AccessTask.h"
#include "HardDrive.h"

class CScan
{
private:
	HardDrive hardDrive;
	std::map<int, AccessTask> map;
	std::vector<AccessTask> waitList;
	int distance = 0;
public:
	CScan(HardDrive hardDrive, std::vector<AccessTask> tab);
	~CScan();

	void run();
	void statistic();
};

