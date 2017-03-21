#include "FCFS.h"


FCFS::FCFS(HardDrive drive, std::vector<AccessTask> tab) : hardDrive(drive)
{
	for (AccessTask a : tab) {
		if (a.getDelay() == 0) {
			queue.push(a);
		}
		else {
			waitList.push_back(a);
		}
	}
	std::sort(waitList.begin(), waitList.end(), [](AccessTask &a, AccessTask &b) {
		return a.getDelay() < b.getDelay(); });
}

void FCFS::run()
{
	int time = 0;
	while (!queue.empty() || !waitList.empty()) {
		if (queue.size() > 0) {
			AccessTask tmp = queue.front();
			queue.pop();
			int move = hardDrive.moveTo(tmp.getBlock());
			distance += move;
			time += move;
		}
		else {
			time++;
		}
		for (;!waitList.empty() && time >= waitList[0].getDelay(); )
		{
			queue.push(waitList[0]);
			waitList.erase(waitList.begin());
		}
	}
}

void FCFS::statistic()
{
	std::cout << "Odleglosc przebyta przez glowice w przypadku FCFS wyniosla: " << distance << std::endl;
}

FCFS::~FCFS()
{
}
