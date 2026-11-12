#include <iostream>
using namespace std;

// This program asks the user for their name and greets them.
int main()
{
    // Store the user's input in a string variable.
    string NameOfThePerson;

    // Ask the user for their name.
    cout << "What is your name, lad?" << endl;

    // Read the input and save it.
    cin >> NameOfThePerson;

    // Display a personalized greeting.
    cout << "Nice to meet you, " << NameOfThePerson << "!" << endl;
    return 0;
}