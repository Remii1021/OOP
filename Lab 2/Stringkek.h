#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Stringkek
{
private:
	std::string strg;
	std::vector<std::pair<std::string, int>> words;
public:
	Stringkek();
	Stringkek(std::string str);
	Stringkek(const Stringkek& strk);
	void displayCount();
	void displaySorted(std::vector<std::pair<std::string, int>> vecPairs);
	int findSub(const std::string& str);
	std::vector<std::pair<std::string, int>> sortByOccLtoH();
	std::vector<std::pair<std::string, int>> sortByOccHtoL();
	std::vector<std::pair<std::string, int>> sortByAlph();
	std::vector<std::pair<std::string, int>> sortByNorm();
	int wordCount();
	bool readFile(std::string str);
	bool outFile(std::string str);
	Stringkek addStrings(const Stringkek& strk1, const Stringkek& strk2);
	Stringkek& operator=(const Stringkek& strk);
	friend std::istream& operator>>(std::istream& is, Stringkek& strk);
	friend std::ostream& operator<<(std::ostream& os, const Stringkek& strk);
	~Stringkek();

};
