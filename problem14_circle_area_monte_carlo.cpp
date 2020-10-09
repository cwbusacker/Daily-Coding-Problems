/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x^2 + y^2 = r^2.
*/

//The area of 1/4th of a circle is pi/4 * r^2
//the area of a square that surrounds this 1/4th of a circule is r^2.
//therefore, the ratio of random points in a circle to total points is approximately
//pi/4 = circle/total points

/* 
Tested this program with different magnitudes of random points:

How many random points would you like in order to estimate pi?10
Pi is approximately 3.6

How many random points would you like in order to estimate pi?100
Pi is approximately 3.16

How many random points would you like in order to estimate pi?1000
Pi is approximately 3.176

How many random points would you like in order to estimate pi?10000
Pi is approximately 3.1444

How many random points would you like in order to estimate pi?100000
Pi is approximately 3.13328

How many random points would you like in order to estimate pi?1000000
Pi is approximately 3.13927

How many random points would you like in order to estimate pi?10000000
Pi is approximately 3.14107

How many random points would you like in order to estimate pi? 100000000
Pi is approximately 3.14173

How many random points would you like in order to estimate pi? 1000000000
Pi is approximately 3.14156

How many random points would you like in order to estimate pi? 10000000000
Pi is approximately 3.14159
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

bool isInCircle(double x, double y, double r)
{
    return x*x+y*y < r*r;
}

//to find pi:
//get a bunch of random coordinate pairs
//calculate whether or not they are in the circle
//Give the value pi =(approx) 4 * circle points / total points.
double runMonteCarloPiEstimator(unsigned long long int numSamples)
{
    double x;
    double y;
    unsigned long long numInCircle = 0;
    for(unsigned long long int sample = 0; sample < numSamples; sample++)
    {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if(isInCircle(x,y, 1))
            numInCircle++;

    }

    return (((double) numInCircle)/ numSamples) * 4;
}


int main()
{
    srand(0); //set up random seed
    unsigned long long int numSamples;
    std::cout << "How many random points would you like in order to estimate pi?";
    std::cin >> numSamples;

    double pi = runMonteCarloPiEstimator(numSamples);
    std::cout << "Pi is approximately " << pi << std::endl;
}