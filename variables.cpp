#include <iostream>
using namespace std;

// This program demonstrates basic variable declaration and arithmetic.
int main()
{
    /*
       Variables are containers for storing data.
       Before using a variable, we must declare its data type.
       Here, we create integer and floating-point variables.
    */
    int a = 47;
    float b = 20.67;

    // Add the two values together and store the result.
    float result = a + b;

    // Display the calculation to the user.
    cout << "The sum of " << a << " and " << b << " is " << result << "." << endl;
    return 0;
}