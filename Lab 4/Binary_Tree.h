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
	void BFSPrivate(Node* nodeptr, std::vector<int>& vector);
	void preorderPrivate(Node* nodeptr, std::vector<int>& vector);
	void postorderPrivate(Node* nodeptr, std::vector<int>& vector);
	void inorderPrivate(Node* nodeptr, std::vector<int>& vector);
	Node* findParentPriv(int data, Node* nodeptr);
	Node* findParent(int data);
	int getData(Node* nodeptr);
	void clear(Node* rootNode);


public:
	BTree();
	BTree(const BTree& tree);
	BTree(std::vector<int> inputV);
	~BTree();
	void operator= (const BTree& tree);
	bool checkData(int data);
	void insert(int data);
	int findMax();
	int findMin();
	int findHeight();
	std::vector<int> printBFS();
	std::vector<int> printPreorder();
	std::vector<int> printPostorder();
	std::vector<int> printInorder();
	void drawTree();
	void del(int data);
};
