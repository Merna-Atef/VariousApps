#include <iostream>
#include "Stack.hpp"

std::string input (int &stringSize)
{
    std::cout<<"Type in the parantheses :"<<std::endl;
    std::string inputChar;
    std::cin >> inputChar;
    stringSize = inputChar.size();
    return inputChar;
}

int main(int argc, char **argv)
{
    int stringSize = 0;
    std::string inputChar = input(stringSize) ;
    CharStack theStack;
    for (int i = 0; i < stringSize; i++)
    {
        if (inputChar[i] != '('&& inputChar[i] != ')')
        {
            std::cout<<"Invalid input please type again."<<std::endl;
            inputChar = input(stringSize);             
        }
    }
    for (int i = 0; i < stringSize; i++)
    {
        if (inputChar[i] == '(')
        {
            theStack.push(inputChar[i]);
        }
        else
        {
            if (theStack.isEmpty())
            {
                std::cout << "Unbalanced" << std::endl;
                exit(0);
            }

            else
                theStack.pop();
        }
    }

    if (theStack.isEmpty())
    {
        std::cout << "balanced" << std::endl;
    }

    else
        std::cout << "Unbalanced" << std::endl;
}
