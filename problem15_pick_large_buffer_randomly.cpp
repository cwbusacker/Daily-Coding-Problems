/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
*/
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

template <class T>
T pickRandomElement(T elements[], unsigned int size)
{
    return elements[rand() % size];
}
int main()
{
    srand(time(0));

    unsigned int size = 0;
    std::cout << "How many elements will be in your buffer? ";
    std::cin >> size;

    //this can be changed to ANY type
    int * intArray = new int[size];

    for(int i = 0; i < size; i++)
    {
        std::cout << "Please enter item #" << i + 1 << ": ";
        std::cin >> intArray[i];
    }

    std::cout << "A random number is: " << pickRandomElement(intArray, size) << std::endl;

    delete [] intArray;

    
}