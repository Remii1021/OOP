#pragma once
class Container
{
public:
	virtual void push(int value) = 0;
	virtual void insert(int value, int pos) = 0;
	virtual void print() = 0;
	virtual void del(int pos) = 0;
	virtual int getSize() = 0;
	virtual int getData(int pos) = 0;
};