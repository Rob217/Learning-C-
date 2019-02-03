#include <iostream>
#include "constants.h"

double height (double h, double t)
{
	double y;
	y = h - myConstants::g * t * t / 2.0;
	return y;
}

int main() 
{

	std::cout << "Enter the height of the tower in meters: ";
	double h;
	std::cin >> h;

	double t = 0;
	double y;
	y = h;
	while (y > 0)
	{
		y = height(h, t);
		if (y > 0) 
			std::cout << "At " << t << " seconds, the ball is at height: " << y << " meters \n";
		else
			std::cout << "At " << t << " seconds, the ball is on the ground. \n";
		t++;
	}

	return 0;
}