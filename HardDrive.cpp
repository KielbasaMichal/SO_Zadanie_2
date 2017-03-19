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
	std::cout << "block: " << block << std::endl;
	int tmp = abs(block - positionHead);
	positionHead = block;
	return tmp;
}

int HardDrive::getPosition()
{
	return positionHead;
}
