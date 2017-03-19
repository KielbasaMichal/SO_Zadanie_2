#include "Scan.h"


Scan::Scan(HardDrive drive, std::vector<AccessTask> tab) : hardDrive(drive)
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

Scan::~Scan()
{
}

void Scan::run()
{
	int time = 0;
	bool direction = false;
	while (!map.empty() || !waitList.empty()) {
		if (map.size() > 0) {
			std::map<int, AccessTask>::iterator it;
			it = map.upper_bound(hardDrive.getPosition());
			if (direction) {
				if (it == map.end()) {
					distance += hardDrive.moveTo(hardDrive.END_BLOCK);
					direction = false;
				}
				else {
					distance += hardDrive.moveTo(it->second.getBlock());
					map.erase(it);
				}
			}
			else {
				it--;
				if (it == map.end()) {
					distance += hardDrive.moveTo(hardDrive.START_BLOCK);
					direction = true;
				}
				else {
					distance += hardDrive.moveTo(it->second.getBlock());
					map.erase(it);
				}
			}

		}
		time++;
		for (; !waitList.empty() && time >= waitList[0].getDelay(); )
		{
			map[waitList[0].getBlock()] = waitList[0];
			waitList.erase(waitList.begin());
		}
	}
}

void Scan::statistic()
{
	std::cout << "Odleglosc przebyta przez glowice w przypadku Scan wyniosla: " << distance << std::endl;
}
