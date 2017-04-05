#include "FDSCAN.h"


FDScan::FDScan(HardDrive harddrive, std::vector<RealTimeTask> tab) : hardDrive(harddrive)
{
	for (RealTimeTask a : tab) {
		if (a.getDelay() == 0) {
			task.push_back(a);
		}
		else
		{
			waitList.push_back(a);
		}
	}

	std::sort(waitList.begin(), waitList.end(), [](RealTimeTask &a, RealTimeTask &b) {
		return a.getDelay() < b.getDelay();
	});

	std::sort(task.begin(), task.end(), [](RealTimeTask &a, RealTimeTask &b) {
		return a.getDeadline() < b.getDeadline();
	});
}

FDScan::~FDScan()
{
}

void FDScan::run()
{
	int time = 0;
	while (!task.empty() || !waitList.empty()) {
		if (task.size() > 0) {
			for(int i = 0; i < task.size(); i++)	
			{
				if (hardDrive.getPosition() == task[i].getBlock())
				{
					task.erase(task.begin() + i);
					i--;
					std::cout << "(O:" << hardDrive.getPosition() << ",K:" << task.begin()->getBlock() << ") ";
				}
			}
			RealTimeTask tmp = task.front();
			int odleglosc = hardDrive.getPosition() - tmp.getBlock();
			if (odleglosc < 0)
			{
				distance += hardDrive.moveTo(hardDrive.getPosition() + 1, false);
			}
			else if (odleglosc > 0)
			{
				distance += hardDrive.moveTo(hardDrive.getPosition() - 1, false);
			}
		}
		else {
			time++;
		}
		bool isAdd = false;
		for (; !waitList.empty() && time >= waitList[0].getDelay(); )
		{
			task.push_back(waitList[0]);
			waitList.erase(waitList.begin());
			isAdd++;
		}
		if (isAdd)
		{
			std::sort(task.begin(), task.end(), [](RealTimeTask &a, RealTimeTask &b) {
				return a.getDeadline() < b.getDeadline();
			});
			isAdd = false;
		}
	}
}

void FDScan::statistic()
{
	std::cout << "Odleglosc przebyta przez glowice w przypadku FD-Scan wyniosla: " << distance << std::endl;
}

