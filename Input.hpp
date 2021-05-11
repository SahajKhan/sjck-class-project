#pragma once
#include <string>
#include <iostream>
#include <limits>

std::string input() {
    std::string String;
    getline(std::cin, String);
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    return String;
}

int input(int min, int max) {
    std::cout << "Please enter a number between " << min << " and " << max << std::endl;
    int userInput;
    std::cin >> userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    if (userInput < min || userInput> max)
        return input(min, max);
    
    return userInput;
}