#include <iostream>

int main()
{
    int num;
    std::cout << "Enter the number to check if it is Prime:\t";

    if (!(std::cin >> num))
    {
        std::cerr << "Invalid Input\n";
        return 1;
    }

    if (num <= 1)
    {
        std::cerr << "Number must be greater than 1\n";
        return 1;
    }

    for (int i = 2; i <= num/i; i++) // we are going till (num)^1/2 bcoz we don't have to go that far
    {
        if (num % i == 0)
        {
            std::cout << "The given number : " << num << " is divisible by " << i << " , so the number is composite\n";
            return 0;
        }
    }
    std::cout << "The given number : " << num << " is prime\n";
    return 0;
}