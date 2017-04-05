#include "EDF.h"

EDF::EDF(HardDrive drive, std::vector<RealTimeTask> tab) : hardDrive(drive)
{
	for (RealTimeTask a : tab) {
		if (a.getDelay() == 0) {
			queue.push(a);
		}
		else {
			waitList.push_back(a);
		}
	}

	std::sort(waitList.begin(), waitList.end(), [](RealTimeTask &a, RealTimeTask &b) {
		return a.getDelay() < b.getDelay();
	});
}


EDF::~EDF()
{
}

void EDF::run()
{
	int time = 0;
	while (!queue.empty() || !waitList.empty()) {
		if (queue.size() > 0) {
			RealTimeTask tmp = queue.top();
			queue.pop();
			int move = hardDrive.moveTo(tmp.getBlock());
			distance += move;
			time += move;
		}
		else {
			time++;
		}
		for (; !waitList.empty() && time >= waitList[0].getDelay(); )
		{
			queue.push(waitList[0]);
			waitList.erase(waitList.begin());
		}
	}
}

void EDF::statistic()
{
	std::cout << "Odleglosc przebyta przez glowice w przypadku EDF wyniosla: " << distance << std::endl;
}
