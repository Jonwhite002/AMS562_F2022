#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    
    // Inputs
    std::string title, name, date, bio;

    // Ask user for their title
    std::cout << "What is your title?" << std::endl;
    std::getline(std::cin, title);

    // Ask user for their date of birth
    std::cout << "What is your date of birth? (MM\\DD\\YY)" << std::endl;
    std::getline(std::cin, date);
    // Split date into tokens w/ space character as delimiter & push into token vector
    char delim = '\\';
    std::istringstream split(date);
    std::vector<std::string> date_Arr;
    for(std::string parse; std::getline(split, parse, delim); date_Arr.push_back(parse));

    std:: cout << "Tell me about yourself" << std::endl;
    std::getline(std::cin, bio);

    // Print all the information
    std::cout << title << std::endl;
    std::cout << '\t' << "DOB: ";
    for(int i = 0; i <= 2; i++)
    {
        std::cout << date_Arr[i] << '\\';
    }
    std::cout << '\n' << '\t' << "Bio: " << bio << std::endl;

    return 0;
}