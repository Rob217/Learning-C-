#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) 
{
	int r;
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	r = min + static_cast<int>((std::rand() * fraction) * (max - min + 1));
	return r;
}


int main() {

	bool playing = true, question, win;
	std::srand(static_cast<int>(std::time(nullptr)));
	int counter, guess;

	while (playing == true)
	{
		static int r;
		r = getRandomNumber(1, 100);
		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";

		counter = 1; 
		win = false;
		while (counter <= 7) 
		{
			std::cout << "Guess #" << counter << ": ";
			std::cin >> guess; 

			if (guess > r)
				std::cout << "Your guess is too high.\n";
			else if (guess < r)
				std::cout << "Your guess was too low.\n";
			else if (guess == r)
			{
				win = true;
				counter = 8;
			}
			counter++;
		} 
		if (win == true)
			std::cout << "Correct! You win!\n";
		else
			std::cout << "Sorry, you lose. The correct number was " << r << ".\n";

		static char playAgain;		
		question = true;
		while (question == true)
		{
			std::cout << "Would you like to play again (y/n)? ";
			std::cin >> playAgain;
			if (playAgain == 'y')
			{
				question = false;
				playing = true;
			}
			else if (playAgain == 'n')
			{
				question = false;
				playing = false;
				std::cout << "Thank you for playing.\n";
			}
		}
		
	}
	


	return 0;
}