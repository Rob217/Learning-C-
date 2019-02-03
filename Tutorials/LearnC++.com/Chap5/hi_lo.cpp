#include <iostream>
#include <random>
#include <ctime>

int getRandom(int min, int max)
{
    std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> die(min, max);

    return die(mersenne);
}

char continueGame()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Would you like to play again (y/n)? ";
        char yn;
        std::cin >> yn;
 
        // Chars can accept any single input character, so no need to check for an invalid extraction here
 
        std::cin.ignore(32767,'\n'); // remove any extraneous input
 
        // Check whether the user entered meaningful input
        if (yn == 'y' || yn == 'n')
            return yn; // return it to the caller
    } // and try again
}

int main() 
{
    int i;
    while (true)
    {
        i = getRandom(1, 100);
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is. \n";

        bool won = false;
        int guess;
        for (int nthGuess = 1; nthGuess <= 7; nthGuess++)
        {
            std::cout << "Guess #" << nthGuess << ": ";
            std::cin >> guess;
            if (guess == i)
            {
                won = true;
                break;
            }
            else if (guess > i)
                std::cout << "Your guess is too high\n";
            else if (guess < i)
                std::cout << "Your guess is too low\n";
        }
        if (won == true)
            std::cout << "Correct! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct number was " << i << ".\n";

        char yn = continueGame();
        if (yn == 'n')
            break;
    }
    return 0;
}
