#pragma once

#include <iostream>
#include <vector>

class BTree
{
private:
	class Node
	{
	public:
		int data;
		Node* left;
		Node* right;
	};
	Node* root;
	Node* createLeaf(int data);
	Node* getNode(int data);
	Node* findIOS(Node* nodeptr);
	void insertPrivate(Node* nodeptr, int data);
	Node* getNodePrivate(int data, Node* nodeptr);
	BTree::Node* delPrivate(int data, Node* nodeptr);
	int findHeightPrivate(Node* nodeptr);
	void drawTreePrivate(int level, Node* nodeptr, bool isLeft);
	void BFSPrivate(Node* nodeptr);
	void preorderPrivate(Node* nodeptr);
	void postorderPrivate(Node* nodeptr);
	void inorderPrivate(Node* nodeptr);
	Node* findParentPriv(int data, Node* nodeptr);
	Node* findParent(int data);
	int getData(Node* nodeptr);
	void clear(Node* rootNode);


public:
	BTree();
	~BTree();
	bool checkData(int data);
	void insert(int data);
	int findMax();
	int findMin();
	int findHeight();
	void printBFS();
	void printPreorder();
	void printPostorder();
	void printInorder();
	void drawTree();
	BTree::Node* del(int data);
};
