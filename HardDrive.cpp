#include "HardDrive.h"

HardDrive::HardDrive(int block, int startPosition) : END_BLOCK(block)
{
	positionHead = startPosition;
}

HardDrive::~HardDrive()
{
}

int HardDrive::moveTo(int block)
{
	return moveTo(block, true);
}

int HardDrive::moveTo(int block, bool statistic)
{
	if (statistic)
	{
		std::cout << block << ", ";
	}
	int tmp = abs(block - positionHead);
	positionHead = block;
	return tmp;
}

int HardDrive::getPosition()
{
	return positionHead;
}
