#include "Binary Tree.h"
#include <iostream>
#include <iomanip>


int findMaxVal(int a, int b)
{
	if (a < b) return b;
	else return a;
}
void printSpace(int level)
{
	for (int i = 0; i < level * 10; i++)
	{
		std::cout << " ";
	}
}
BTree::BTree()
{
	Node* root = nullptr;
}

BTree::Node* BTree::createLeaf(int data)
{
	Node* leaf = new Node();
	leaf->data = data;
	leaf->left = nullptr;
	leaf->right = nullptr;
	return leaf;
}

int BTree::getData(BTree::Node* node)
{
	return node->data;
}
void BTree::insert(int data)
{
	insertPrivate(root, data);
}

void BTree::insertPrivate(Node* nodeptr, int data)
{
	if (root == nullptr)
	{
		root = createLeaf(data);
	}
	else if (data < nodeptr->data)
	{
		if (nodeptr->left != nullptr)
		{
			insertPrivate(nodeptr->left, data);
		}
		else
		{
			nodeptr->left = createLeaf(data);
		}
	}
	else if (data > nodeptr->data)
	{
		if (nodeptr->right != nullptr)
		{
			insertPrivate(nodeptr->right, data);
		}
		else
		{
			nodeptr->right = createLeaf(data);
		}
	}
	else
	{
		std::cerr << "Data already exists in tree" << std::endl;
		return;
	}
}
BTree::Node* BTree::getNode(int data)
{
	return getNodePrivate(data, root);
}

BTree::Node* BTree::getNodePrivate(int data, Node* nodeptr)
{
	if (nodeptr != nullptr)
	{
		if (nodeptr->data == data)
		{
			return nodeptr;
		}
		else if (data < nodeptr->data)
		{
			return getNodePrivate(data, nodeptr->left);
		}
		else
		{
			return getNodePrivate(data, nodeptr->right);
		}
	}
	else
	{
		return nullptr;
	}
}
bool BTree::checkData(int data)
{
	if (root != nullptr)
	{
		Node* node = getNode(data);
		if (node != nullptr)
		{
			std::cout << "Data found in tree" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Data not found in tree" << std::endl;
			return false;
		}
	}
	else
	{
		std::cerr << "Tree is empty" << std::endl;
		return false;
	}
}
BTree::Node* BTree::findParent(int data)
{
	return findParentPriv(data, root);
}
BTree::Node* BTree::findParentPriv(int data, Node* nodeptr) {
	if (nodeptr != nullptr) {  // Check if nodeptr is not null
		if (nodeptr->left != nullptr && nodeptr->left->data == data) {  // Check left child
			return nodeptr; // Parent found
		}
		else if (nodeptr->right != nullptr && nodeptr->right->data == data) {  // Check right child
			return nodeptr; // Parent found
		}
		else if (data < nodeptr->data) {
			return findParentPriv(data, nodeptr->left); // Recursive call on left subtree
		}
		else if (data == root->data)
		{
			return nullptr;
		}
		else {
			return findParentPriv(data, nodeptr->right); // Recursive call on right subtree
		}
	}
	else {
		return nullptr; // Node not found
	}
}


int BTree::findMax()
{
	Node* current = root;
	if (current != nullptr)
	{
		while (current->right != nullptr)
		{
			current = current->right;
		}
		return current->data;
	}
	else
	{
		std::cerr << "Tree is empty" << std::endl;
		return 0;
	}
}
int BTree::findMin()
{
	Node* current = root;
	if (current != nullptr)
	{
		while (current->left != nullptr)
		{
			current = current->left;
		}
		return current->data;
	}
	else
	{
		std::cerr << "Tree is empty" << std::endl;
		return 0;
	}
}
BTree::Node* BTree::findIOS(Node* nodeptr) {
	if (nodeptr->right != nullptr) {  // Check for right child first (efficiency)
		Node* temp = nodeptr->right;
		while (temp->left != nullptr) { // Traverse down left subtree of right child
			temp = temp->left;
		}
		return temp; // Inorder successor is leftmost child in right subtree
	}

	Node* temp = nodeptr;
	while (temp != nullptr && temp->left != nullptr) {
		temp = temp->left;
	}

	// Check if temp has a right child (inorder successor for left-right nodes)
	return (temp != nullptr) ? temp->right : nullptr;
}

int BTree::findHeight()
{
	return findHeightPrivate(root);
}

int BTree::findHeightPrivate(Node* nodeptr)
{
	if (nodeptr == nullptr)
	{
		return -1;
	}
	int leftHeight = findHeightPrivate(nodeptr->left);
	int rightHeight = findHeightPrivate(nodeptr->right);
	int height = findMaxVal(leftHeight, rightHeight) + 1;
	return height;
}
void BTree::BFSPrivate(Node* nodeptr)
{
	std::vector<Node*> queue;
	std::vector<Node*> vNodes;
	if (nodeptr != nullptr)	queue.push_back(nodeptr);

	while (!queue.empty())
	{
		nodeptr = queue.front();
		queue.erase(queue.begin());

		vNodes.push_back(nodeptr);
		if (nodeptr->left != nullptr)
		{
			queue.push_back(nodeptr->left);
		}
		if (nodeptr->right != nullptr)
		{
			queue.push_back(nodeptr->right);
		}
	}
	for (int i = 0; i < vNodes.size(); i++)
	{
		std::cout << vNodes[i]->data << " ";
	}
	std::cout << std::endl;
}
void BTree::preorderPrivate(Node* nodeptr)
{
	if (nodeptr == nullptr) return;
	std::cout << nodeptr->data << " ";
	preorderPrivate(nodeptr->left);
	preorderPrivate(nodeptr->right);
}
void BTree::inorderPrivate(Node* nodeptr)
{
	if (nodeptr == nullptr) return;
	inorderPrivate(nodeptr->left);
	std::cout << nodeptr->data << " ";
	inorderPrivate(nodeptr->right);
}
void BTree::postorderPrivate(Node* nodeptr)
{
	if (nodeptr == nullptr) return;
	postorderPrivate(nodeptr->left);
	postorderPrivate(nodeptr->right);
	std::cout << nodeptr->data << " ";
}
void BTree::drawTreePrivate(int level, Node* nodeptr, bool isLeft)
{
	if (nodeptr == nullptr) return;
	drawTreePrivate(level + 1, nodeptr->right, false);
	printSpace(level);
	std::cout << nodeptr->data << std::endl;
	std::cout << std::endl;
	drawTreePrivate(level + 1, nodeptr->left, true);
}

void BTree::printBFS()
{
	BFSPrivate(root);
	std::cout << std::endl;
}
void BTree::printPreorder()
{
	preorderPrivate(root);
	std::cout << std::endl;
}
void BTree::printInorder()
{
	inorderPrivate(root);
	std::cout << std::endl;
}
void BTree::printPostorder()
{
	postorderPrivate(root);
	std::cout << std::endl;
}
void BTree::drawTree()
{
	drawTreePrivate(0, root, false);
}

BTree::Node* BTree::del(int data)
{
	if (checkData(data))
	{
		return delPrivate(data, getNode(data));
	}
	else
	{
		std::cerr << "Data not found in tree" << std::endl;
		return nullptr;
	}
}

BTree::Node* BTree::delPrivate(int data, Node* nodeptr)
{
	{
		if (nodeptr == nullptr)
		{
			return nullptr;
		}
		Node* parent = findParent(data);
		
		if  (nodeptr->left == nullptr && nodeptr->right == nullptr)
		{
			if (parent != nullptr) {
				if (data < parent->data) {
					parent->left = nullptr;
				}
				else {
					parent->right = nullptr;
				}
			}
			delete nodeptr;
			return nullptr;
		}
		else if (nodeptr->left == nullptr)
		{
			Node* temp = nodeptr->right;
			if (parent != nullptr)
			{
				if (data < parent->data) {
					parent->left = nodeptr->right;
				}
				else {
					parent->right = nodeptr->right;
				}
			}
			delete nodeptr;
			return temp;
		}
		else if (nodeptr->right == nullptr)
		{
			Node* temp = nodeptr->left;
			if (parent != nullptr)
			{
				if (data < parent->data)
				{
					parent->left = nodeptr->left;
				}
				else
				{
					parent->right = nodeptr->left;
				}
			}
			delete nodeptr;
			return temp;
		}
		else
		{
			Node* temp = findIOS(nodeptr);

			
			if (nodeptr == root) {
				
				Node* successorParent = findParent(temp->data);

				
				if (successorParent != nodeptr) { 
					successorParent->left = temp->right;
				}
				else {
					root->right = temp->right;
				}
				nodeptr->data = temp->data;
				delete temp;
			}
			else
			{
				int tempdata = temp->data;
				nodeptr->right = delPrivate(temp->data, nodeptr->right);
				nodeptr->data = tempdata;
			}
		}
		return nodeptr;
	}
}
void BTree::clear(Node* rootNode)
{
	if (rootNode != nullptr) return;
	clear(rootNode->right);
	clear(rootNode->left);
	delete rootNode;
}
BTree::~BTree()
{
	clear(root);
}
