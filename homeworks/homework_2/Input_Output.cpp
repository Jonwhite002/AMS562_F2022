#include <iostream>
#include <string>

int main() {
    
    // Inputs
    std::string title, firstName, lastName, month, day, year, bio;

    // Ask user for their title and name
    std::cout << "What is your title, first name and last name?" << std::endl;
    std::cin >> title >> firstName >> lastName;

    // Ask user for their date of birth
    std::cout << "What is your date of birth? (month, day, year))" << std::endl;
    std::cin >> month >> day >> year;
    
    // Ask user to fill in their bio
    std::cin.ignore();
    std:: cout << "Please fill in your bio:" << std::endl;
    std::getline(std::cin, bio);

    // Print out all the information
    std::cout << '\n' << title << ' ' << firstName << ' ' << lastName << std::endl;
    std::cout << '\t' << "DOB: " << month << '\\' << day << '\\' << year << std::endl;
    std::cout << '\t' << "Bio: " << bio << '\n' << std::endl;

    return 0;
}