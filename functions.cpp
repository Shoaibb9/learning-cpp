#include <iostream>

// This function multiplies two integers and returns the result.
int multiply(int a, int b)
{
    return a * b;
}

// This is the main program entry point.
int main()
{
    // Declare two numbers to multiply.
    int x = 14, y = 33;

    // Call the helper function and store the result.
    int product = multiply(x, y);

    // Print the result in a friendly sentence.
    std::cout << "If we multiply " << x << " with " << y << " we get " << product << " as the answer." << std::endl;
    return 0;
}