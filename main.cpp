#include "head.h"

#include "AccessTask.h"
#include "RealTimeTask.h"
#include "FCFS.h"
#include "SSTF.h"
#include "Scan.h"
#include "CScan.h"
#include "EDF.h"
#include "FDSCAN.h"

using namespace std;

//https://www.ii.pwr.edu.pl/~juszczyszyn/so.htm

int main()
{
	std::vector<AccessTask> data;
	ifstream in;
	in.open("data.txt");
	int ile;
	in >> ile;
	for(int i = 0; i < ile; i++)
	{
		int a;
		in >> a;
		data.push_back(AccessTask(a));
	}
	in.close();

	std::vector<RealTimeTask> rtData;
	in.open("data.txt");
	in >> ile;
	for (int i = 0; i < ile; i++)
	{
		int a, b;
		in >> a >> b;
		rtData.push_back(RealTimeTask(a, b));
	}


	srand((unsigned int)time(NULL));
	int startPosition = (rand() % 800) + 1;
	std::cout << "\nPozycja startowa wynosi: " << startPosition << "\n\n";
	HardDrive hardDrive(1000, startPosition);

	FCFS fcfs(hardDrive, data);
	fcfs.run();
	std::cout << std::endl;
	fcfs.statistic();

	std::cout << "\n\n";

	SSTF sstf(hardDrive, data);
	sstf.run();
	std::cout << std::endl;
	sstf.statistic();

	std::cout << "\n\n";

	Scan scan(hardDrive, data);
	scan.run();
	std::cout << std::endl;
	scan.statistic();

	std::cout << "\n\n";
	
	CScan cscan(hardDrive, data);
	cscan.run();
	std::cout << std::endl;
	cscan.statistic();

	std::cout << "\n\n";
	std::cout << "Alorytmy real time";
	std::cout << "\n\n";

	EDF edf(hardDrive, rtData);
	edf.run();
	std::cout << std::endl;
	edf.statistic();

	std::cout << "\n\n";

	FDScan fdscan(hardDrive, rtData);
	fdscan.run();
	std::cout << std::endl;
	fdscan.statistic();

	std::cout << "\n\n";

	int a;
	cin >> a;
}