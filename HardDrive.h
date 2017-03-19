#pragma once
#include "head.h"

class HardDrive
{
private:
	int positionHead;

public:
	const int START_BLOCK = 0;
	const int END_BLOCK;

	HardDrive(int block, int startPosition);
	~HardDrive();

	int moveTo(int block);	//zwraca przemieszczenie glowicy
	int getPosition();
};

