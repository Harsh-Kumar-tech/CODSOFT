#include <iostream>
#include <cstdlib>
#include <ctime>
int main(){
    // Get a different random number each time the program runs
    srand(time(0));
    // Generate a random number between 0 and 100
    int randomNum = rand()%101;
    int userGuess = 0;
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;
    std::cout << "Try to guess it!" << std::endl;
    // Loop until the user guesses the correct number
    while (userGuess != randomNum) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        if (userGuess > randomNum) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (userGuess < randomNum) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number correctly!" << std::endl;
        }
    }
    return 0;
}
