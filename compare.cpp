#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Enter the first number: " << std::endl;
    std::cin >> num1;
    std::cout << "Enter the second number: " << std::endl;
    std::cin >> num2;

    if (num1 == num2)
    {
        std::cout << "Both are equal." << std::endl;
    }
    else if (num1 > num2)
    {
        std::cout << "The first number " << num1 << " is greater than the second number " << num2 << "." << std::endl;
    }
    else
    {
        std::cout << "The second number " << num2 << " is greater than the first number " <<num1 <<"." << std::endl;
    }

    return 0;
}