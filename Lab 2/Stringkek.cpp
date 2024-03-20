#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <utility>
#include <cctype>
#include "Stringkek.h"

Stringkek::Stringkek()
{
	strg = "";
}

Stringkek::Stringkek(std::string str)
{
	strg = str;
	std::string currword;
	if (!words.empty())
	{
		words.clear();
	}
	for (size_t i = 0; i < strg.size(); i++)
	{
		if (strg[i] == ' ' || strg[i] == '\t' || strg[i] == '\n' || strg[i] == '\r' || strg[i] == '.' || strg[i] == ',' || strg[i] == '!' || strg[i] == '?' || strg[i] == ';' || strg[i] == ':')
		{
			if (!currword.empty())
			{
				for (char& c : currword) {
					c = std::tolower(c);
				}
				std::vector<std::pair<std::string, int>>::iterator it;
				bool found = false;
				for (it = words.begin(); it != words.end(); it++)
				{
					if (it->first == currword)
					{
						it->second++;
						found = true;
						currword.clear();
						break;
					}
				}
				if (!found)
				{
					words.push_back(std::make_pair(currword, 1));
					currword.clear();
				}
			}
		}
		else
		{
			currword += strg[i];
		}
	}
}
Stringkek::Stringkek(const Stringkek& string)
{
	this->strg = string.strg;
	this->words = string.words;
}
int length(std::string s) 
{
	int counter = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		counter++;
	}
	return counter;
}
void Stringkek::displayCount()
{
	std::cout << "The word count in the sentence: " << strg << " Is: " << std::endl;
	std::vector<std::pair<std::string, int>>::const_iterator it;
	for (it = words.begin(); it < words.end(); it++)
	{
		std::cout << "The Word " << "\"" << it->first << "\"" << " Is iterated " << it->second << " Time(s)" << std::endl;
	}
}
void Stringkek::displaySorted(std::vector<std::pair<std::string, int>> vecPairs)
{
	std::cout << "The word count in the sentence: " << strg << " Is: " << std::endl;

	for (size_t i = 0; i < vecPairs.size(); ++i)
	{
		const std::pair<std::string, int>& wordPair = vecPairs[i];
		std::cout << "The Word \"" << wordPair.first << "\"" << " Is iterated " << wordPair.second << " Time(s)" << std::endl;
	}
}
int Stringkek::findSub(const std::string& str) 
{
	size_t hayLength = strg.length();
	size_t needleLength = str.length();

	if (needleLength > hayLength) 
	{
		std::cout << "Search query is longer than the original string!" << std::endl;
		return -1;
	}

	for (size_t i = 0; i <= hayLength - needleLength; i++) 
	{
		bool found = true;
		for (size_t j = 0; j < needleLength; j++) 
		{
			if (strg[i + j] != str[j]) {
				found = false;
				break;
			}
		}
		if (found) 
		{
			std::cout << "Substring found! Returning index." << std::endl;
			return i;
		}
	}

	std::cout << "Substring not found! Returning default value." << std::endl;
	return -1;
}

std::vector<std::pair<std::string, int>> Stringkek::sortByOccLtoH()
{
	int currOcc = 100000;
	for (int i = 0; i < words.size(); i++)
	{
		if (currOcc > words[i].second)
		{
			currOcc = words[i].second;
		}
	}
	std::vector<std::pair<std::string, int>> tempVec;
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words.size(); j++)
		{
			if (currOcc == words[j].second)
			{
				tempVec.push_back(words[j]);
			}
		}
		currOcc++;
	}
	return tempVec;
}
std::vector<std::pair<std::string, int>> Stringkek::sortByOccHtoL()
{
	int currOcc = 0;
	for (int i = 0; i < words.size(); i++)
	{
		if (currOcc < words[i].second)
		{
			currOcc = words[i].second;
		}
	}
	std::vector<std::pair<std::string, int>> tempVec;
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words.size(); j++)
		{
			if (currOcc == words[j].second)
			{
				tempVec.push_back(words[j]);
			}
		}
		currOcc--;
	}
	return tempVec;
}
std::vector<std::pair<std::string, int>> Stringkek::sortByAlph() {
	char currLetter = 'A';
	std::vector<std::pair<std::string, int>> tempVec;
	while (currLetter <= 'Z') 
	{
		for (const auto& wordPair : words)
		{
			if (wordPair.first[0] == currLetter || wordPair.first[0] - 32 == currLetter) 
			{
				tempVec.push_back(wordPair);
			}
		}
		currLetter++;
	}

	return tempVec;
}

std::vector<std::pair<std::string, int>> Stringkek::sortByNorm()
{
	Stringkek temp(*this);
	return temp.words;
}

int Stringkek::wordCount()
{
	int wordCount = 0;
	bool inWord = false;

	for (char c : strg) 
	{
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':') 
		{
			if (inWord) 
			{
				wordCount++;
				inWord = false;
			}
		}
		else 
		{
			inWord = true;
		}
	}

	if (inWord) {
		wordCount++;
	}

	return wordCount;
}
bool Stringkek::readFile(std::string str)
{
	std::string tempStr = "";
	std::ifstream inp(str);
	if (inp.is_open())
	{
		std::getline(inp, tempStr);
		Stringkek tempStrk(tempStr);
		*this = tempStrk;
		inp.close();
		return true;
	}
	else
	{
		std::cerr << "File not found!" << std::endl;
		return false;
	}
}
bool Stringkek::outFile(std::string str)
{
	std::ofstream outFile(str);

	if (outFile.is_open()) 
	{
		outFile << "Output: " << strg << std::endl;
		outFile << "The word count in the sentence: " << strg << " Is: \n";
		std::vector<std::pair<std::string, int>>::const_iterator it;
		for (it = words.begin(); it != words.end(); ++it) {
			const std::string& word = it->first;
			int count = it->second;
			outFile << "The Word \"" << word << "\"" << " Is iterated " << count << " Time(s)\n";
		}

		outFile.close();
		return true;
	}
	else {
		std::cerr << "Error: Could not open file for writing!" << std::endl;
		return false;
	}
}
Stringkek::~Stringkek()
{
	strg.clear();
	words.clear();
}
Stringkek Stringkek::addStrings(const Stringkek& strk1, const Stringkek& strk2)
{
	std::string tempStr = strk1.strg + strk2.strg;
	Stringkek temp(tempStr);
	return temp;
}
Stringkek& Stringkek::operator=(const Stringkek& strk)
{
	if (this != &strk)
	{
		strg = strk.strg;
		words = strk.words;
	}
	return *this;
}

std::istream& operator>>(std::istream& is, Stringkek& strk)
{
	std::string input;
	is >> input;
	strk = Stringkek(input);
	return is;

}
std::ostream& operator<<(std::ostream& os, const Stringkek& strk)
{
	os << strk.strg;
	return os;
}