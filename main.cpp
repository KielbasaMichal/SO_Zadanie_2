#include "head.h"

#include "AccessTask.h"
#include "FCFS.h"
#include "SSTF.h"
#include "Scan.h"
#include "CScan.h"

using namespace std;

//https://www.ii.pwr.edu.pl/~juszczyszyn/so.htm

int main()
{
	std::vector<AccessTask> data;
	data.push_back(AccessTask(10, 0));
	data.push_back(AccessTask(15, 0));
	data.push_back(AccessTask(8, 0));
	data.push_back(AccessTask(2, 0));
	data.push_back(AccessTask(10, 6));

	HardDrive hardDrive(20, 6);

	FCFS fcfs(hardDrive, data);
	fcfs.run();
	fcfs.statistic();

	std::cout << "\n\n";

	SSTF sstf(hardDrive, data);
	sstf.run();
	sstf.statistic();

	std::cout << "\n\n";

	Scan scan(hardDrive, data);
	scan.run();
	scan.statistic();

	std::cout << "\n\n";
	
	CScan cscan(hardDrive, data);
	cscan.run();
	cscan.statistic();


	int a;
	cin >> a;
}