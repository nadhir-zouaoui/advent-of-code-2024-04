// advent-of-code-2024-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
int valide(std::string ch) {
    if (ch == "XMAS")
        return 1;
    else return 0;
}
std::string behindX(std::string content, int i) {
    std::string test;
    int j = i;
    while (j >=0 && j > i - 4) {
        test += content[j];
        j--;
    }
    return test;
}
std::string inFrontOfX(std::string content, int maxLength, int i) {
    std::string test;
    int j = i;
    while (j < maxLength && j < i + 4) {
        test += content[j];
        j++;
    }
    return test;
}
std::string underX(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j < maxLength && count < 4) {
        test += content[j];
        j+= lineSize;
        count++;
    }
    return test;
}
std::string upperX(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j >= 0 && count < 4) {
        test += content[j];
        j -= lineSize;
        count++;
    }
    return test;
}
std::string rightLowerDiag(std::string content, int maxLength, int i, int lineSize) {
    std::string test;
    int j = i;
    int count = 0;
    while (j < maxLength && count < 4) {
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
    while (j < maxLength && count < 4) {
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
    while (j >= 0 && count < 4) {
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
    while (j >= 0 && count < 4) {
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
    int j;
    for (int i = 0; i < maxLength; i++)
    {
        if (content[i]=='X')
        {
            std::string test;
            test = behindX(content, i);
            s += valide(test);
            test = inFrontOfX(content, maxLength, i);
            s += valide(test);
            test = underX(content, maxLength, i, lineSize);
            s += valide(test);
            test = upperX(content, maxLength, i, lineSize);
            s += valide(test);
            test = rightLowerDiag(content, maxLength, i, lineSize);
            s += valide(test);
            test = leftLowerDiag(content, maxLength, i, lineSize);
            s += valide(test);
            test = rightUpperDiag(content, maxLength, i, lineSize);
            s += valide(test);
            test = leftUpperDiag(content, maxLength, i , lineSize);
            s += valide(test);
        }
    }
    std::cout << s << std::endl;
    std::cout << "Hello World!\n";
}

