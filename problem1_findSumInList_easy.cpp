#include <iostream>
using std::cout;
using std::cin;

bool findSum(float array[], float sum, uint length)
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
            else
            {
                cout << array[index] << "+" << array[index2] << " != " << sum  << " != " << array[index] + array[index2] << std::endl;
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

    float * array = new float[size];
    for(uint x = 0; x < size; x++)
    {
        cout << "Enter number " << x + 1 << ": ";
        cin >> array[x];
    }

    float sum;
    cout << "What sum of two numbers are you looking for? ";
    cin >> sum;



    cout << "Two numbers that add up to " << sum << (findSum(array, sum, size) ? " was found\n" : " was not found\n");
}