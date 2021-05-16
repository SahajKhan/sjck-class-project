/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 Author:        Sahaj Khan
 *************************************************/
#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <ctime>
#include <stdlib.h>

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

bool coinFlip() { //true if heads, false if tails
    srand((unsigned) time(0));
    int result = rand()%2; //returns 0 or 1 randomly
    if (result == 1)
        std::cout << "The coin toss resulted in Heads\n";
    else
        std::cout << "The coin toss resulted in Tails\n";
    
    return result;
}