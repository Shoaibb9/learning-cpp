// C++ program to demonstrate the scope resolution operator
// The scope resolution operator (::) is used to access a global variable when there is a local variable with the same name.
#include <iostream>

int gl = 67;
int main()
{
    int gl = 12;
    // Displaying the value of local and global variable
    std::cout << "The value of local variable is " << gl << std::endl;
    // Using scope resolution operator to access global variable
    std::cout << "The value of global variable is " << ::gl << std::endl;
    if (gl == ::gl)
    {
        std::cout << "Both are equal" << std::endl;
    }
    else
    {
        std::cout << "Both are not equal" << std::endl;
    }

    // Demonstrating the use of float, double, and long double literals
    float f = 3.14;
    std::cout << "The value of the float 3.14 is " << f << std::endl;
    std::cout << "The value of the float 3.14f is " << 3.14f << std::endl;
    std::cout << "The value of the float 3.14l is " << 3.14l << std::endl;

    // Demonstrating the use of reference variables
    int x = 10;
    int &ref = x; // ref is a reference to x
    std::cout << "The value of x is " << x << std::endl;
    std::cout << "The value of ref is " << ref << std::endl;

    // Demonstrating the use of C-style casting
    float num1 = 10.5;
    int CastedNum = (int)num1; // C-style cast
    // (int)num1 is also equal to int(num1)
    std::cout << "The value of num1 is " << num1 << std::endl;
    std::cout << "The value of CastedNum is " << CastedNum << std::endl;

    // Demonstrating the use of C++-style casting
    float num2 = 20.5;
    int CastedNum2 = static_cast<int>(num2); // C++-style cast
    std::cout << "The value of num2 is " << num2 << std::endl;
    std::cout << "The value of CastedNum2 is " << CastedNum2 << std::endl;

    return 0;
}