#pragma once

#include <iostream>
#include "Container.h"

class LList :public Container
{
private:
	class Node
	{
	public:
		Node* Next;
		int val;
		int value;
		Node(int value) : val(value), Next(nullptr) {};
		Node() : val(0), Next(nullptr) {};
	};
	Node* head = nullptr;
	int size = 0;
public:
	LList();
	LList(int data);
	LList(const LList& llist);
	~LList();

	int& operator[](int pos);
	int operator[](int pos)const;
	LList& operator=(const LList& list);
	LList operator+(const LList& otherList) const;

	virtual void push(int value)override;
	virtual void insert(int value, int pos)override;
	virtual void print()override;
	virtual void del(int pos)override;
	virtual int getSize()override;
	virtual int getData(int pos)override;
};
