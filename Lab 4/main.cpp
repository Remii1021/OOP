#include <iostream>
#include "Binary Tree.h"
#include <vector>
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
	std::cout << oak.findMax() << std::endl;
	std::cout << oak.findMin() << std::endl;
	std::cout << "Height = " << oak.findHeight() << std::endl;
	oak.drawTree();
	while (true)
	{
		int sort;
		int delchoice;
		std::cout << "1. BFS traversal" << std::endl;
		std::cout << "2. Inorder traversal" << std::endl;
		std::cout << "3. Preorder traversal" << std::endl;
		std::cout << "4. Postorder traversal" << std::endl;
		std::cin >> sort;
		switch (sort)
		{
		case 1:
			oak.printBFS();
			break;
		case 2:
			oak.printPreorder();
			break;
		case 3:
			oak.printInorder();
			break;
		case 4:
			oak.printPostorder();
			break;
		case 5:
			std::cin >> delchoice;
			oak.del(delchoice);
			oak.drawTree();

		case 6:
			oak.checkData(4);
		}
	}
}