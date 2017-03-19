#pragma once
#include "head.h"
#include "AccessTask.h"
#include "HardDrive.h"

class Scan
{
private:
	HardDrive hardDrive;
	std::map<int, AccessTask> map;
	std::vector<AccessTask> waitList;
	int distance = 0;
public:
	Scan(HardDrive hardDrive, std::vector<AccessTask> tab);
	~Scan();

	void run();
	void statistic();
};

