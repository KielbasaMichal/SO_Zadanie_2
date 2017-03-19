#include "SSTF.h"

SSTF::SSTF(HardDrive drive, std::vector<AccessTask> tab) : hardDrive(drive)
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

SSTF::~SSTF()
{
}

void SSTF::run()
{
	int time = 0;
	while (!map.empty() || !waitList.empty()) {
		if(map.size() > 0) {
			std::map<int, AccessTask>::iterator it, it2;
			it = map.upper_bound(hardDrive.getPosition());
			it2 = it--;
			if (it2 == map.end()) {
				it2 = it;
			}
			else if (it == map.end()) {
				it = it2;
			}
			int odl1 = abs(it->second.getBlock() - hardDrive.getPosition());
			int odl2 = abs(it2->second.getBlock() - hardDrive.getPosition());
			if (odl1 <= odl2) {
				distance += hardDrive.moveTo(it->second.getBlock());
				map.erase(it);
			}
			else if (odl2 < odl1) {
				distance += hardDrive.moveTo(it2->second.getBlock());
				map.erase(it2);
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

void SSTF::statistic()
{
	std::cout << "Odleglosc przebyta przez glowice w przypadku SSTF wyniosla: " << distance << std::endl;
}
