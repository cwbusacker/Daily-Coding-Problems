#include <iostream>
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
bool findSum(double array[], double sum, uint length)
{
    double result;
    for(uint index = 0; index < length; index++)
    {
        for(uint index2 = index + 1; index2 < length; index2++)
        {
            result = array[index] + array[index2];
            if(result > sum - 0.000001 && result < sum + 0.000001)
            {
                return true;
            }
        }
    }

    return false;

}



int main()
{
    uint size;
    cout << "How many numbers in your list? ";
    cin >> size;

    double * array = new double[size];
    for(uint x = 0; x < size; x++)
    {
        cout << "Enter number " << x + 1 << ": ";
        cin >> array[x];
    }

    double sum;
    cout << "What sum of two numbers are you looking for? ";
    cin >> sum;



    cout << "Two numbers that add up to " << sum << (findSum(array, sum, size) ? " was found\n" : " was not found\n");
}