#include <iostream>
#include <fstream>
#include "Stringkek.h"
int main()
{
	Stringkek test;
	int x = 0;
	int y = 0;
	bool ex = false;
	std::cout << "========================" << std::endl;
	std::cout << "        MENU            " << std::endl;
	std::cout << "========================" << std::endl;
	std::cout << "1. Load Text from File" << std::endl;
	std::cout << "2. Print current Text and word order" << std::endl;
	std::cout << "3. Search Substring" << std::endl;
	std::cout << "4. Sort" << std::endl;
	std::cout << "5. Count Words" << std::endl;
	std::cout << "6. Save Text to File" << std::endl;
	std::cout << "0. Exit" << std::endl;

	do {
		std::cout << "Enter your choice: ";
		std::cin >> x;
		switch (x)
		{
		case 1:
		{
			std::string file;
			std::cout << "Enter the filename: ";
			std::cin.ignore();
			std::getline(std::cin, file);
			if (test.readFile(file)) {
				std::cout << "File loaded successfully!" << std::endl;
			}
			else {
				std::cerr << "Error loading file!" << std::endl;
			}
			break;
		}
		case 2:
			std::cout << test << std::endl;
			test.displayCount();
			break;
		case 3:
		{
			std::cout << "Enter the Search Querry: ";
			std::string tempstr;
			std::cin >> tempstr;
			std::cout << std::endl;
			int sub = test.findSub(tempstr);
			if (sub == -1)
			{
				std::cout << "Substring was not found inside the given string." << std::endl;
			}
			else
			{
				std::cout << "Substring " << "\"" << tempstr << "\"" << " Was found at position: " << sub << "." << std::endl;
			}
			break;
		}
		case 4:
		{
			std::vector<std::pair<std::string, int>> sorted;
			std::cout << "Sort by?\n";
			std::cout << "1. Alphabetical (A-Z)\n";
			std::cout << "2. Occurrence (Most frequent to Least frequent)\n";
			std::cout << "3. Occurrence (Least frequent to Most frequent)\n";
			std::cout << "4. Original Sorting";
			std::cout << "Enter your choice (1-4): ";
			std::cin >> y;
			switch (y)
			{
			case 1:
				sorted = test.sortByAlph();
				std::cout << "Sorted by Alphabetical (A-Z)\n";
				test.displaySorted(sorted);
				break;
			case 2:
				sorted = test.sortByOccHtoL();
				std::cout << "Sorted by Occurrence (Most frequent to Least frequent)\n";
				test.displaySorted(sorted);
				break;
			case 3:
				sorted = test.sortByOccLtoH();
				std::cout << "Sorted by Occurrence (Least frequent to Most frequent)\n";
				test.displaySorted(sorted);
				break;
			case 4:
				sorted = test.sortByNorm();
				std::cout << "Sorted by Original word order\n";
				test.displaySorted(sorted);
				
				break;
			default:
				std::cout << "Error! Enter a number through 1-4!!!" << std::endl;
				break;
			}
			break;
		}
		case 5:
		{
			int wordCount = test.wordCount();
			std::cout << "This string contains: " << "\"" << wordCount << "\"" << " Word(s)." << std::endl;
			break;
		}
		case 6:
		{
			std::string file = "output.txt";
			if (test.outFile(file))
			{
				std::cout << "File saved successfully!" << std::endl;
			}
			else
			{
				std::cout << "File does not exist! Try again." << std::endl;
			}
			break;
		}
		case 7:
		{
			Stringkek temp3;
			temp3 = temp3.addStrings(test, test);
			std::cout << temp3 << std::endl;
			break;
		}
		case 0:
		{
			std::cout << "Exitting...." << std::endl;
			ex = true;
			break;
		}
		default:
			std::cout << "Please select an option from the menu..." << std::endl;
			break;
		}
	} while (!ex);
	return 0;
}