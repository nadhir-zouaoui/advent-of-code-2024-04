// advent-of-code-2024-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
int isValidXmasString(std::string ch) {
	if (ch == "XMAS")
		return 1;
	else return 0;
}
std::string subStringAroundX(std::string content, int startIndex, int step) {
	std::string test;
	int j = startIndex;
	for (size_t i = 0; i < 4 && j >= 0 && j < content.size(); i++)
	{
		test += content[j];
		j += step;
	}
	return test;
}

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open()) {
		std::cout << "failed to open" << std::endl;
		return 1;
	}
	std::string line;
	std::getline(file, line);
	int lineSize = line.size() + 1;
	file.seekg(-lineSize - 1, std::ios::cur);
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	int s = 0;
	int maxLength = content.size();
	int j;
	for (int i = 0; i < maxLength; i++)
	{
		if (content[i] == 'X')
		{
			std::string test;
			test = subStringAroundX(content, i, -1);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, 1);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, lineSize);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, -lineSize);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, lineSize + 1);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, lineSize - 1);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, -lineSize + 1);
			s += isValidXmasString(test);
			test = subStringAroundX(content, i, -lineSize - 1);
			s += isValidXmasString(test);

		}
	}
	std::cout << s << std::endl;
	std::cout << "Hello World!\n";
}

