
#include <iostream>
using std::cout;
bool findSum(int array[], int sum, int length)
{
    for(int index = 0; index < length; index++)
    {
        for(int index2 = index; index2 < length; index2++)
        {
            if(array[index] + array[index2] == sum)
            {
                return true;
            }
        }
    }

    return false;

}



int main()
{
    int array[] = {2, 14, 17, 128, 19, 26};
    int sum = 1000;
    int length = sizeof(array)/sizeof(array[0]);

    cout << "Two numbers that add up to " << sum << (findSum(array, sum, length) ? " was found\n" : " was not found\n");
}