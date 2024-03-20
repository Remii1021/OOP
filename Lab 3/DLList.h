#pragma once
#include <iostream>
#include "Container.h"
class DLList : public Container
{
private:
	class Node
	{
	public:
		Node* Next;
		Node* Prev;
		int val;
		Node(int value) : val(value), Next(nullptr), Prev(nullptr) {};
		Node() : val(0), Next(nullptr), Prev(nullptr) {};
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
public:
	DLList();
	DLList(int value);
	~DLList();

	int& operator[](int pos);
	int operator[](int pos)const;
	DLList& operator=(const DLList& list);
	DLList operator+(const DLList& otherList) const;

	int getSize();
	int getData(int pos);
	void print()override;
	void push(int value)override;
	void del(int pos)override;
	void insert(int value, int pos)override;
};