#include <iostream>

int main()
{
    // Declare variables to store the student's information.
    char student_name[100];
    float math, physics, chemistry;
    int student_id;

    // Get the student's name.
    std::cout << "Enter the name of the Candidate:" << std::endl;
    std::cin.getline(student_name, 100);

    // Get the student's ID.
    std::cout << "Enter the id of the student:" << std::endl
              << "1607051-";
    std::cin >> student_id;

    // Get the marks for each subject.
    std::cout << "Enter the marks candidate recieved in Math" << std::endl;
    std::cin >> math;
    std::cout << "Enter the marks candidate recieved in Physics" << std::endl;
    std::cin >> physics;
    std::cout << "Enter the marks candidate recieved in Chemistry" << std::endl;
    std::cin >> chemistry;

    // Validate that all marks are in the valid range (0 to 100).
    if (math < 0 || math > 100 || physics < 0 || physics > 100 || chemistry < 0 || chemistry > 100)
    {
        std::cout << "Invalid marks entered. Please enter marks between 0 and 100." << std::endl;
        return 1;
    }

    // Display the candidate's basic information.
    std::cout << "Candidate Name: " << student_name << std::endl;
    std::cout << "Student ID: 1607051-" << student_id << std::endl;

    // Calculate the average percentage after reading the marks.
    const float percentage = (math + physics + chemistry) / 3.0;

    // Check if the student has failed in any subject.
    if (math < 36 || physics < 36 || chemistry < 36)
    {
        std::cout << "Candidate has failed to pass the GP-Engineering Examination!." << std::endl
                  << "Hence the report card for the candidate cannot be generated." << std::endl;
        return 0;
    }

    // If the student passed all subjects, show the overall result.
    else
    {
        std::cout << "Candidate has passed the GP-Engineering Examination!." << std::endl
                  << "The Candidate has scored " << percentage << "% in the Examination." << std::endl;
    }

    // Determine the grade based on the percentage.
    if (percentage >= 85)
    {
        std::cout << "The Candidate has secured an \"A\" Grade." << std::endl;
    }
    else if (percentage >= 70)
    {
        std::cout << "The Candidate has secured a \"B\" Grade." << std::endl;
    }
    else if (percentage >= 55)
    {
        std::cout << "The Candidate has secured a \"C\" Grade." << std::endl;
    }
    else if (percentage >= 45)
    {
        std::cout << "The Candidate has secured a \"D\" Grade." << std::endl;
    }
    else
    {
        std::cout << "The Candidate has secured a \"E\" Grade." << std::endl;
    }

    // Check if all subject marks are equal.
    if (math == physics && physics == chemistry)
    {
        float equal_marks = math; // Since all marks are equal, we can use any of them.
        std::cout << "The Candidate has scored equal marks in all subjects." << std::endl;
        std::cout << "Hence the Candidate has secured " << equal_marks << " in all subjects." << std::endl;
    }
    // Check for equal highest marks in Math and Physics.
    else if (math == physics && math > chemistry)
    {
        std::cout << "The Candidate has scored equal marks in Math and Physics." << std::endl;
        std::cout << "Hence the Candidate has secured " << math << " in both subjects." << std::endl;
    }
    // Check for equal highest marks in Math and Chemistry.
    else if (math == chemistry && math > physics)
    {
        std::cout << "The Candidate has scored equal marks in Math and Chemistry." << std::endl;
        std::cout << "Hence the Candidate has secured " << math << " in both subjects." << std::endl;
    }
    // Check for equal highest marks in Physics and Chemistry.
    else if (physics == chemistry && physics > math)
    {
        std::cout << "The Candidate has scored equal marks in Physics and Chemistry." << std::endl;
        std::cout << "Hence the Candidate has secured " << physics << " in both subjects." << std::endl;
    }
    // Find the subject with the highest marks.
    else if (math > physics && math > chemistry)
    {
        std::cout << "The Candidate has scored the highest marks in Math." << std::endl;
        std::cout << "The Candidate has scored " << math << " in Math." << std::endl;
    }
    else if (physics > math && physics > chemistry)
    {
        std::cout << "The Candidate has scored the highest marks in Physics." << std::endl;
        std::cout << "The Candidate has scored " << physics << " in Physics." << std::endl;
    }
    else if (chemistry > math && chemistry > physics)
    {
        std::cout << "The Candidate has scored the highest marks in Chemistry." << std::endl;
        std::cout << "The Candidate has scored " << chemistry << " in Chemistry." << std::endl;
    }

    return 0;
}