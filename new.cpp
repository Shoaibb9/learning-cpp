#include <iostream>

int main()
{
    char name[100];
    int age;
    float height;
    char initial = name[0];
    char studying;
    bool student;

    std::cout << "Aye mate, What's your good name?" << std::endl;
    std::cin.get(name, 100);
    std::cout << "That's alright " << name << "!" << std::endl;
    std::cout << "How old are you " << name << "?" << std::endl;
    std::cin >> age;
    std::cout << "Can you please enter your height in centimeters (cms)?" << std::endl;
    std::cin >> height;
    std::cout << "Are you a student? (Y/N)" << std::endl;
    std::cin >> studying;
    if (studying == 'y' || studying == 'Y')
    {
        student = true;
    }
    else
    {
        student = false;
    }

    for (int i = 0; i < 60; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "PERSONAL IDENTITY CARD" << std::endl;
    for (int i = 0; i < 60; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "NAME: \t\t\t" << name << std::endl;
    std::cout << "AGE: \t\t\t" << age << std::endl;
    std::cout << "HEIGHT: \t\t" << height << std::endl;
    std::cout << "STUDENT/STUDYING: \t";
    if (student)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    for (int i = 0; i < 60; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
    

    return 0;
}