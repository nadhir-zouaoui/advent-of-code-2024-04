// advent-of-code-2024-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int isValidXmasString(std::string diag1, std::string diag2) {
    if (diag1 == "MAS" && diag2 == "MAS")
        return 1;
    else return 0;
}
std::string subStringAroundChar(std::string content, int startIndex, int step) {
    std::string test;
    int j = startIndex;
    j -= step;
    if (j <= 0 || j > content.size()) return test;
    test += content[j];
    j += step;
    if (j <= 0 || j > content.size()) return test;
    test += content[j];
    j += step;
    if (j <= 0 || j > content.size()) return test;
    test += content[j];
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
    int lineSize = line.size()+1;
    file.seekg(-lineSize - 1, std::ios::cur);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    int s = 0;
    int maxLength = content.size();
    for (int i = 0; i < maxLength; i++)
    {
        if (content[i]=='A')
        {
            std::string diag1 = subStringAroundChar(content, i, lineSize + 1);
            std::string diag2 = subStringAroundChar(content, i, lineSize - 1);
            std::string diag3 = subStringAroundChar(content, i, -lineSize + 1);
            std::string diag4 = subStringAroundChar(content, i, -lineSize - 1);
            s += isValidXmasString(diag1, diag3) + isValidXmasString(diag1, diag2) + isValidXmasString(diag2, diag3) + isValidXmasString(diag3, diag4) + isValidXmasString(diag2, diag4) + isValidXmasString(diag4, diag1);
        }

    }
    std::cout << s << std::endl;
    std::cout << "Hello World!\n";
}

