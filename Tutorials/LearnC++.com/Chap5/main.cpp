#include <iostream>
#include "constants.h"

// get additional height from user and return it
double getInitialHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;
    return initialHeight;
}

// return heigh from ground after "secondsPassed" seconds
double calculateHeight(double initialHeight, int secondsPassed)
{
    // using formula: [ s = u * t + (a * t^2) / 2 ] , where u(initial velocity) = 0
    
