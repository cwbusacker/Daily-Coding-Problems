/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array,
 compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and 
you do not need to store the results. You can simply print them out as you compute them.
*/
#include <deque>
#include <iostream>


void displaySubarrayMaxWindowFinder(int array[], int size, int k)
{
    std::deque<std::size_t> windowIndexDeque;
    std::size_t i;
    for(i = 0; i < k; i++)
    {
        //remove elements that are smaller than arr[i], forcing the biggest element to the front.
        while(!windowIndexDeque.empty() && array[i] >= array[windowIndexDeque.back()])
            windowIndexDeque.pop_back();

        windowIndexDeque.push_back(i);
    }
    std::cout << "{ ";
    for(; i < size; i++)
    {
        std::cout << array[windowIndexDeque.front()] << ", ";

        //remove elems that are not in the windoow
        while(!windowIndexDeque.empty() && windowIndexDeque.front() <= i - k)
            windowIndexDeque.pop_front();

        //remove elements that are smaller than arr[i], forcing the biggest element to the front.
        while(!windowIndexDeque.empty() && array[i] >= array[windowIndexDeque.back()])
            windowIndexDeque.pop_back();

        //add the next index to the window
        windowIndexDeque.push_back(i);
    }

    std::cout << array[windowIndexDeque.front()] << " }\n";

}




int main()
{
    //should print out {32238, 32238, 121416, 121416, 411442, 411442. 490234, 490234} when k = 3
    int array[] = {10123, 3124, 32238, 15, 121416, 21481, 411442, 0, 1, 490234, 4};
    displaySubarrayMaxWindowFinder(array, 11, 3);

}