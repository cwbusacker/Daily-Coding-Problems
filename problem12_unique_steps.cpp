/*
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 
1 or 2 steps at a time. Given N, write a function that returns 
the number of unique ways you can climb the staircase. 
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1: 1
2: 2
3: 3
4: 5
5:


1, 1, 1, 1 - single number means only 1 way
2, 2

2, 1, 1 - 1 that's different means (int)(NUMSTEPS/COMMON_NUM) + 1 different ways
1, 2, 1
1, 1, 2



What if, instead of being able to climb 1 or 2 steps at a time, 
you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

#include <vector>
#include <iostream>
/*
    computeNumberUniquePaths will determine the number of ways to create a sum using
    the numbers found in numStepsAtATime. (See problem statement above.)
 */ 
int computeNumberUniquePaths(unsigned int numSteps, std::vector<unsigned int> numStepsAtATime)
{
    std::vector<int> arr(numSteps + 1, 0);
    arr[0] = 1;
    if(numStepsAtATime.empty())
    {
        return 0; //no way to climb if not allowed to go up.
    }
    for(unsigned int i = 1; i <= numSteps; i++)
    {
        for(unsigned int j = 0; j < numStepsAtATime.size(); j++)
        {
            //make sure the array doesn't go out of bounds.
            if(i >= numStepsAtATime[j])
            {
            
                //the number of ways to go up after we've gone up only one of the numStepsAtATime
                //I.E. numSteps = 3 and numStepsAtaTime = {1,2,3}
                //arr[1] = arr[1 - 1] = 1 (only 1 way to go up 1 stair...go all the way up)
                //arr[2] = arr[2 - 1] + arr[2 - 2] = 2 
                //arr[3] = arr[3 - 1] + arr[3 - 2] + arr[3 - 3] = 2 + 1 + 1 = 4
                //In other words when I have 5 steps to climb,
                // there are arr[3 - 1] more ways to go up, after taking 1 step (2 more steps to go)
                // there are arr[3 - 2] more ways to go up, after taking 2 steps (1 more steps to go)
                // and there are arr[3 - 3] more ways to go up, after taking 3 steps (0 more steps to go)
                
                arr[i] += arr[i - numStepsAtATime[j]];
            }
        }
    }

    return arr[numSteps];
}

int main()
{
    std::vector<unsigned int> numSteps;
    numSteps.push_back(12);
    numSteps.push_back(3);
    numSteps.push_back(1);
    numSteps.push_back(9);

    //Should be 150 ways.
    std::cout << "There are " << computeNumberUniquePaths(14, numSteps) << " possible ways to go up the stairs.\n";
}