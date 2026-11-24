#include <iostream>

constexpr bool isEven(int number)
{
    return number % 2 == 0;
    
}
int main()
{
    int number;
    std::cout << "Enter a number to check if it is odd or even: \t";
    if (!(std::cin>> number))
    {
        std::cerr << "Invalid Input\n";
        return 1;
    }
    else
    {
        isEven(number) ? std::cout << "The number is even\n" : std::cout << "The number is odd\n";
        
    }

}