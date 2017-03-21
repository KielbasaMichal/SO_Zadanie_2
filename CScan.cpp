#include "CScan.h"


CScan::CScan(HardDrive drive, std::vector<AccessTask> tab) : hardDrive(drive)
{
	for (AccessTask a : tab) {
		if (a.getDelay() == 0) {
			map[a.getBlock()] = a;
		}
		else
		{
			waitList.push_back(a);
		}
	}

	std::sort(waitList.begin(), waitList.end(), [](AccessTask &a, AccessTask &b) {
		return a.getDelay() < b.getDelay();
	});
}

CScan::~CScan()
{
}

void CScan::run()
{
	int time = 0;
	while (!map.empty() || !waitList.empty()) {
		if (map.size() > 0) {
			std::map<int, AccessTask>::iterator it;
			it = map.upper_bound(hardDrive.getPosition());
			it--;
			if (it == map.end()) {
				distance += hardDrive.moveTo(hardDrive.START_BLOCK);
				time++;
				int move = hardDrive.moveTo(hardDrive.END_BLOCK);
				distance += move;
				time += move;
			}
			else {
				int move = hardDrive.moveTo(it->second.getBlock());
				distance += move;
				time += move;
				map.erase(it);
			}
		}
		else {
			time++;
		}
		for (; !waitList.empty() && time >= waitList[0].getDelay(); )
		{
			map[waitList[0].getBlock()] = waitList[0];
			waitList.erase(waitList.begin());
		}
	}
}

void CScan::statistic()
{
	std::cout << "Odleglosc przebyta przez glowice w przypadku C-Scan wyniosla: " << distance << std::endl;
}
