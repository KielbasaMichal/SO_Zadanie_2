#include "head.h"

#include "AccessTask.h"
#include "FCFS.h"
#include "SSTF.h"
#include "Scan.h"
#include "CScan.h"

#include "RealTimeTask.h"
#include "EDF.h"
using namespace std;

//https://www.ii.pwr.edu.pl/~juszczyszyn/so.htm

int main()
{
	std::vector<AccessTask> data;
	data.push_back(AccessTask(10));
	data.push_back(AccessTask(13));
	data.push_back(AccessTask(8));
	data.push_back(AccessTask(17));
	data.push_back(AccessTask(2));
	data.push_back(AccessTask(25, 50));
	data.push_back(AccessTask(50));
	data.push_back(AccessTask(98));
	data.push_back(AccessTask(78));

	HardDrive hardDrive(100, 15);

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

	std::cout << "\n===========================\nDla aplikacji real-time\n";

	std::vector<RealTimeTask> data2;
	data2.push_back(RealTimeTask(10,1));
	data2.push_back(RealTimeTask(17,45));
	data2.push_back(RealTimeTask(15,5));
	data2.push_back(RealTimeTask(8,7));
	data2.push_back(RealTimeTask(2,20));
	data2.push_back(RealTimeTask(50,15));
	data2.push_back(RealTimeTask(98,10));
	data2.push_back(RealTimeTask(78,8));

	EDF edf(hardDrive, data2);
	edf.run();
	edf.statistic();

	std::cout << "\n\n";

	int a;
	cin >> a;
}