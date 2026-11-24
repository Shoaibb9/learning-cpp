#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <sstream>

bool isValidName(std::string_view name)
{
    for (char character : name)
    {
        if (std::isalpha(static_cast<unsigned char>(character)))
        {
            return true;
        }
    }

    return false;
}

bool readAge(int& age)
{
    std::string input;
    if (!std::getline(std::cin, input))
    {
        return false;
    }

    std::istringstream ageInput{input};
    char extraCharacter;
    return (ageInput >> age) && age >= 0 && !(ageInput >> extraCharacter);
}

void printOldernga( std::string_view name1, std::string_view name2, int age1, int age2)
{
    if(age1 == age2)
    {
        std::cout << "Both guys, " << name1 << " (" << age1 << ") and " << name2 << " (" << age2 << ") are of same age.\n";
    }
    else if(age1 > age2)
    {
        std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ") .\n";
    }
    else if (age1 < age2)
    {
        std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ") .\n";
    }
    
}
int main()
{
    std::string name1, name2;
    int age1, age2;

    std::cout << "Enter the name of the the first person: \n";
    if (!std::getline(std::cin, name1) || !isValidName(name1))
    {
        std::cout << "Wrong input.\n";
        return 1;
    }

    std::cout << "Enter the age of the first person: \n";
    if (!readAge(age1))
    {
        std::cout << "Wrong input.\n";
        return 1;
    }

    std::cout << "Enter the name of the second person: \n";
    if (!std::getline(std::cin, name2) || !isValidName(name2))
    {
        std::cout << "Wrong input.\n";
        return 1;
    }

    std::cout << "Enter the age of the second person: \n";
    if (!readAge(age2))
    {
        std::cout << "Wrong input.\n";
        return 1;
    }

    printOldernga(name1,name2,age1,age2);

    
    return 0;
}