// advent-of-code-2024-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>


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
        if (content[i]=='A')
        {
            bool TopLeftToRightBottom = false;
            bool RightTopToLeftBottom = false;
            bool leftBottomToRightTop = false;
            bool rightBottomToTopLeft = false;
            if (i >= lineSize + 1 && i + lineSize + 1 < maxLength && content[i - lineSize - 1] == 'M' && content[i + lineSize + 1] == 'S') {
                TopLeftToRightBottom = true;
            }
            if (i >= lineSize - 1 && i + lineSize - 1 < maxLength && content[i + lineSize - 1] == 'S' && content[i - lineSize + 1]=='M')
            {
                RightTopToLeftBottom =true;
            }
            if (i >= lineSize - 1 && i + lineSize - 1 < maxLength && content[i + lineSize - 1] == 'M' && content[i - lineSize + 1]=='S')
            {
                leftBottomToRightTop = true;
            }
            if (i >= lineSize + 1 && i + lineSize + 1 < maxLength && content[i + lineSize + 1] == 'M' && content[i - lineSize -1] == 'S')
            {
                rightBottomToTopLeft = true;
            }
            if ((TopLeftToRightBottom && RightTopToLeftBottom) ||
                (TopLeftToRightBottom && leftBottomToRightTop) || 
                (rightBottomToTopLeft && RightTopToLeftBottom) || 
                (rightBottomToTopLeft && leftBottomToRightTop))
            {
                s++;
            }
        }

    }
    std::cout << s << std::endl;
    std::cout << "Hello World!\n";
}

