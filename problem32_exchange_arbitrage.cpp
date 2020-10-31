
#include <vector>
#include <algorithm>
#include <iostream>

void displayRunningMedian(std::vector<double> list)
{
    int halfwayWalker = 0;
    double median;
    for(int i = 0; i < list.size(); i++) 
    {
        std::sort(list.begin(), list.begin() + i + 1);

        if(i % 2 == 0) //odd (starting with 0 is 1 element)
        {
            median = list[halfwayWalker];
            std::cout << "The median so far is: " << median << std::endl;
        }
        else
        {
            median = (list[halfwayWalker] + list[halfwayWalker + 1]) / 2;
            std::cout << "The median so far is: " << median << std::endl;
            halfwayWalker++;
        }
        
    }
}

int main()
{
    std::vector<double> runningMedianVector;
    runningMedianVector.push_back(2);
    runningMedianVector.push_back(1);
    runningMedianVector.push_back(5);
    runningMedianVector.push_back(7);
    runningMedianVector.push_back(2);
    runningMedianVector.push_back(0);
    runningMedianVector.push_back(5);
    runningMedianVector.push_back(7);
    runningMedianVector.push_back(1);
    runningMedianVector.push_back(9);

    displayRunningMedian(runningMedianVector);


}