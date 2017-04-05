#pragma once
#include "head.h"
#include "RealTimeTask.h"
#include "HardDrive.h"

class FDScan
{
private:
	HardDrive hardDrive;
	std::vector<RealTimeTask> task;
	std::vector<RealTimeTask> waitList;
	int distance = 0;
public:
	FDScan(HardDrive hardDrive, std::vector<RealTimeTask> tab);
	~FDScan();

	void run();
	void statistic();

};

