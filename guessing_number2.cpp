// Copyright(c) 2022 Venika Sem All rights reserved.
//
// Created by: Venika Sem
// Created on: Oct 2022
// This program gets the user to guess a number correctly or incorrectly

#include <iostream>
#include <random>
#include <string>

int main() {
    // creating variables

    std::string userNumberAsString;
    int randomNumber;
    int userNumberAsNumber;

    // random generator
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);

    // input
    std::cout << "Enter a number between 0 and 9: ";
    std::cin >> userNumberAsString;

    // process and output
    try {
        userNumberAsNumber = std::stoi(userNumberAsString);
        if (userNumberAsNumber == randomNumber) {
            std::cout << "You guessed right" << std::endl;
        } else {
            std::cout << "You guessed incorrectly, the number was "
                      << randomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << userNumberAsString << "" <<" is not an integer."
        << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Done.";
}
