#pragma once
class AccessTask
{
private:
	int accessBlock;
	int delay;
public:
	AccessTask();
	AccessTask(int block);
	AccessTask(int block, int time);
	~AccessTask();
	
	int getBlock() const;
	int getDelay() const;
};

