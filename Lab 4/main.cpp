#include <iostream>
#include "Binary Tree.h"
#include <vector>
void tempPrint(std::vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	BTree oak;
	oak.insert(10);
	oak.insert(5);
	oak.insert(15);
	oak.insert(4);
	oak.insert(16);
	oak.insert(6);
	oak.insert(17);
	oak.insert(14);
	oak.insert(18);
	oak.insert(20);
	BTree birch = oak;
	while (true)
	{
		int sort;
		int delchoice;
		std::cout << "1. BFS traversal" << std::endl;
		std::cout << "2. Preorder traversal" << std::endl;
		std::cout << "3. Inorder traversal" << std::endl;
		std::cout << "4. Postorder traversal" << std::endl;
		std::cout << "5. Delete element" << std::endl;
		std::cout << "6. Check for elements" << std::endl;
		std::cout << "7. Print tree" << std::endl;
		std::cout << "8. Insert to tree" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cin >> sort;
		switch (sort)
		{
		case 1:
		{
			std::vector<int> tempSort;
			tempSort = oak.printBFS();
			BTree spruce(tempSort);
			spruce.drawTree();
			tempPrint(tempSort);
			break;
		}
		case 2:
		{
			std::vector<int> tempSort;
			tempSort = oak.printPreorder();
			tempPrint(tempSort);
			break;
		}	
		case 3:
		{
			std::vector<int> tempSort;
			tempSort = oak.printInorder();
			tempPrint(tempSort);
			break;
		}
		case 4:
		{
			std::vector<int> tempSort;
			tempSort = oak.printPostorder();
			tempPrint(tempSort);
			break;
		}
		case 5:
			std::cin >> delchoice;
			oak.del(delchoice);
			oak.drawTree();
			break;
		case 6:
		{
			int searchChoice;
			std::cout << "Enter element to search for" << std::endl;
			std::cin >> searchChoice;
			oak.checkData(searchChoice);
			break;
		}
		case 7:
			oak.drawTree();
			break;
		case 8:
			std::cout << "Enter number to insert: ";
			int insertChoice;
			std::cin >> insertChoice;
			std::cout << std::endl;
			oak.insert(insertChoice);
			break;
		case 0:
			std::cout << "Exitting...." << std::endl;
			return 0;
		}
	}
}