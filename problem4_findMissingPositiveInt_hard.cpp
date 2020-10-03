#include <iostream>
#include <map>
using std::cout;
using std::cin;

/****
 * This problem was recently asked by Google.
 *
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 *
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 ****/

std::pair<int, int> getTwoNums(int * array, unsigned int size, int sum)
{
    std::pair<int, int> retVal(-1, -1);
    std::map<int, int> sumMap;
    if(sum == -2)
    {
        retVal.first = 0;
        retVal.second = 0;
    }

    for(int i = 0; i < size; i++)
    {
        if(sumMap.find(array[i]) != sumMap.end())
        {
            retVal.first = array[i];
            retVal.second = sumMap[array[i]];
            return retVal;
        }
        else
        {
            sumMap.insert(std::pair<int, int> (sum - array[i], array[i]));
            cout << "Inserting pair " << sum - array[i] << " " << array[i] << std::endl;
        }
        
    }
    return retVal;

}

int main()
{
    int size;
    cout << "How many numbers in your list? ";
    cin >> size;

    int * array = new int[size];
    for(uint x = 0; x < size; x++)
    {
        cout << "Enter number " << x + 1 << ": ";
        cin >> array[x];
    }

    int sum;
    cout << "What sum of 2 numbers are you looking for? ";
    cin >> sum;

    std::pair<int, int> twoNums = getTwoNums(array, size, sum);

    if(twoNums.first + twoNums.second != sum)
    {
        cout << "No two numbers in the list can add together and make the sum of " << sum << std::endl;
    }
    else
    {
        cout << "The two numbers are " << twoNums.first << " and " << twoNums.second << std::endl;
    }
    


}