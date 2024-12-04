// advent-of-code-2024-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
int valide(std::string ch, std::string ch1) {
    if (ch == "MAS" && ch==ch1)
        return 1;
    else return 0;
}
std::string rightLowerDiag(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j < maxLength && count < 3) {
        test += content[j];
        j += lineSize+1;
        count++;
    }
    return test;
}
std::string leftLowerDiag(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j < maxLength && count < 3) {
        test += content[j];
        j += lineSize - 1;
        count++;
    }
    return test;
}
std::string rightUpperDiag(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j >= 0 && count < 3) {
        test += content[j];
        j = j - lineSize + 1;
        count++;
    }
    return test;
}
std::string leftUpperDiag(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j >= 0 && count < 3) {
        test += content[j];
        j -= lineSize +1 ;
        count++;
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
    int lineSize = line.size()+1;
    file.seekg(-lineSize - 1, std::ios::cur);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    int s = 0;
    int maxLength = content.size();
    std::string test1;
    std::string test2;
    for (int i = 0; i < maxLength; i++)
    {
        if (content[i]=='M')
        {
            test1 = rightLowerDiag(content, maxLength, i, lineSize);
            i += 2;
            test2 = leftLowerDiag(content, maxLength, i, lineSize);
            s += valide(test1,test2);
            test1 = rightUpperDiag(content, maxLength, i, lineSize);
            test2 = leftUpperDiag(content, maxLength, i , lineSize);
            s += valide(test1,test2);
        }
    }
    std::cout << s << std::endl;
    std::cout << "Hello World!\n";
}

