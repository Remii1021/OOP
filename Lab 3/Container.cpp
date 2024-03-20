#include <iostream>
#include "Container.h"
#include "LList.h"
#include "DLList.h"

LList::LList()
{
	head = nullptr;
	size = 0;
}
LList::LList(int data)
{
	Node* newNode = new Node();
	newNode->val = data;
	newNode->Next = nullptr;
	head = newNode;
	size = 1;
}

LList::LList(const LList& llist) {

	head = new Node(llist.head->val);
	size = 1;

	Node* current = llist.head->Next;
	Node* temp = head;
	while (current) {
		temp->Next = new Node(current->val);
		temp = temp->Next;
		current = current->Next;
		size++;
	}
}

int& LList::operator[](int pos)
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	if (temp == nullptr)
	{
		throw std::out_of_range("Index out of range.");
		return pos;
	}
	return temp->val;
}
int LList::operator[](int pos)const
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	if (temp == nullptr)
	{
		throw std::out_of_range("Index out of range.");
		return pos;
	}
	return temp->val;
}

LList& LList::operator=(const LList& list)
{
	this->head = list.head;
	return *this;
}

LList LList::operator+(const LList& otherList) const {
	LList newList;
	Node* current = head;
	while (current != nullptr) {
		newList.push(current->val);
		current = current->Next;
	}
	current = otherList.head;
	while (current != nullptr) {
		newList.push(current->val);
		current = current->Next;
	}
	return newList;
}


void LList::push(int value) {
	Node* newNode = new Node(value);
	if (newNode == nullptr) {
		std::cerr << "Memory allocation failed..." << std::endl;
		return;
	}

	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->Next != nullptr) {
			temp = temp->Next;
		}
		temp->Next = newNode;
	}
	size++;
}


void LList::insert(int value, int pos)
{
	if (size == 0) {
		head = new Node(value);
		size++;
	}
	else if (pos == 0)
	{
		Node* newNode = new Node(value);
		newNode->Next = head;
		head = newNode;
		size++;
	}
	else if (pos == size)
	{
		push(value);
	}
	else if (pos > size+1)
	{
		std::cerr << "Out of range..." << std::endl;
	}
	else
	{
		Node* newNode = new Node(value);
		Node* temp = head;
		Node* temp2 = nullptr;
		for (int i = 0; i < pos-1; i++)
		{
			temp = temp->Next;
		}
		temp2 = temp->Next;
		temp->Next = newNode;
		newNode->Next = temp2;
		size++;
	}
}

void LList::print()
{
	Node* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->val << std::endl;
		temp = temp->Next;
	}
}

void LList::del(int pos) 
{
	if (size == 0) 
	{
		std::cerr << "List already empty..." << std::endl;
	}
	else if (size == 1) 
	{
		head = nullptr;
		size--;
	}
	else if (pos == 0) 
	{
		Node* temp = head;
		head = temp->Next;
		free(temp);
		size--;
	}
	else if (pos >= size)
	{
		std::cerr << "Out of bounds..." << std::endl;
	}
	else 
	{
		Node* temp = head;
		Node* temp2 = nullptr;
		for (int i = 0; i < pos - 1; i++) 
		{
			temp2 = temp;
			temp = temp->Next;
		}
		if (temp2 != nullptr) 
		{
			temp2->Next = temp->Next;
			free(temp);
		}
		size--;
	}
}


int LList::getSize()
{
	return size;
}

int LList::getData(int pos)
{
	Node* temp = head;
	if (pos >= size)
	{
		std::cerr << "Out of range" << std::endl;
		return 0;
	}
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	return temp->val;
}

LList::~LList()
{
	Node* a = head;
	while (a != nullptr)
	{
		Node* temp = a->Next;
		delete a;
		a = temp;
	}
}


DLList::DLList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
DLList::DLList(int value)
{
	Node* newNode = new Node();
	newNode->val = value;
	newNode->Next = nullptr;
	newNode->Prev = nullptr;
	head = newNode;
	tail = newNode;
	size = 1;
	if (head == nullptr)
	{
		std::cerr << "Memory allocation failed while creating new List..." << std::endl;
		return;
	}
}
int DLList::operator[](int pos)const
{
	if (pos >= size) 
	{
		std::cerr << "Out of range..." << std::endl;
		return 0;
	}
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	return temp->val;
}
int& DLList::operator[](int pos)
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	if (temp == nullptr)
	{
		throw std::out_of_range("Index out of range.");
		return pos;
	}
	return temp->val;
}

DLList& DLList::operator=(const DLList& list)
{
	this->head = list.head;
	return *this;
}

DLList DLList::operator+(const DLList& otherList) const {
	DLList newList;
	Node* current = head;
	while (current != nullptr) {
		newList.push(current->val);
		current = current->Next;
	}
	current = otherList.head;
	while (current != nullptr) {
		newList.push(current->val);
		current = current->Next;
	}
	return newList;
}

int DLList::getSize()
{
	return size;
}
int DLList::getData(int pos)
{
	Node* temp = head;
	if (pos >= size)
	{
		std::cerr << "Out of range" << std::endl;
		return 0;
	}
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	return temp->val;
}

void DLList::print()
{
	if (head == nullptr) 
	{
		std::cerr << "List is empty..." << std::endl;
		return;
	}
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->val;
		if (temp->Next != nullptr) 
		{
			std::cout << " , ";
		}
		temp = temp->Next;
	}
	std::cout << std::endl;
}

void DLList::push(int value)
{
	Node* newNode = new Node(value);
	if (newNode == nullptr) {
		std::cerr << "Memory allocation failed while pushing..." << std::endl;
		return;
	}

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
	}
	else if (head == tail)
	{
		head->Next = newNode;
		tail = newNode;
		tail->Prev = head;
		size++;
	}
	else
	{
		Node* temp = tail;
		if (temp == nullptr) {
			std::cerr << "Memory allocation failed while pushing(temp=tail)..." << std::endl;
			return;
		}
		newNode->Prev = temp;
		temp->Next = newNode;
		tail = newNode;
		Node* tempdebug = head;
		size++;
	}
}

void DLList::del(int pos)
{
	if (size == 0)
	{
		std::cerr << "List already empty..." << std::endl;
	}
	else if (pos >= size)
	{
		std::cerr << "Out of bounds..." << std::endl;
	}

	if (size == 1)
	{
		head = nullptr;
		tail = nullptr;
		size--;
	}
	else if (pos == 0)
	{
		Node* temp = head;
		head = temp->Next;
		free(temp);
		head->Prev = nullptr;
		size--;
	}
	else if (pos == size-1)
	{
		Node* temp = tail;
		tail = temp->Prev;
		tail->Next = nullptr;
		free(temp);
		size--;
	}
	else
	{
		Node* temp = head;
		Node* tempNext;
		Node* tempPrev;
		for (int i = 0; i < pos; i++)
		{
			temp = temp->Next;
		}
		tempNext = temp->Next;
		tempPrev = temp->Prev;
		tempNext->Prev = tempPrev;
		tempPrev->Next = tempNext;
		free(temp);
		size--;
	}
}
void DLList::insert(int value, int pos)
{
	if (size == 0) {
		head = new Node(value);
		tail = head;
		size++;
	}
	else if (pos >= size)
	{
		push(value);
	}
	else if (pos == 0)
	{
		Node* newNode = new Node(value);
		newNode->Next = head;
		head->Prev = newNode;
		head = newNode;
		size++;
	}
	else
	{
		Node* newNode = new Node(value);
		Node* temp = head;
		Node* temp2 = nullptr;
		for (int i = 0; i < pos-1; i++)
		{
			temp = temp->Next;
		}
		temp2 = temp->Next;
		if (temp2 == nullptr)
		{
			newNode->Next = head;
			head = newNode;
			size++;
		}
		else
		{
			temp->Next = newNode;
			temp2->Prev = newNode;
			newNode->Next = temp2;
			newNode->Prev = temp;
			size++;
		}
	}
}
DLList::~DLList()
{
	Node* a = head;
	while (a != nullptr) 
	{
		Node* temp = a->Next;
		delete a;
		a = temp;
	}
}