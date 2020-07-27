#include <iostream>
using std::cout;
using std::cin;
/***
 * This problem was asked by Uber.
 *
 * Given an array of integers, return a new array such that each element at index i of 
 * the new array is the product of all the numbers in the original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be 
 * [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6]
 ***/

/*
 * createProductArray will loop through each number of the array
 * to create the product array while skipping the current index. 
 */
int * createProductArray(int array[], uint size)
{
    int * productArray = new int[size];
    for(int i = 0; i < size; i++)
    {
        productArray[i] = 1;
        for(int j = 0; j < size; j++)
        {
            if(j == i)
                continue;

            productArray[i] *= array[j];
            
        }
    }

    return productArray;

}

/*
 * createProductArrayUsingDivision will compute the total product of the entire array
 * and then divide out the current index. 
 */
int * createProductArrayUsingDivision(int array[], uint size)
{
    int * productArray = new int[size];
    int totalProduct = 1;
    for(int i = 0; i < size; i++)
    {
        totalProduct *= array[i];
    }

    for(int i = 0; i < size; i++)
    {
        productArray[i] = totalProduct / array[i];
    }

    return productArray;

}


template <class T>
void displayList(T * array, uint size)
{
     cout << "[ ";

    bool first = true;
     for(uint i = 0; i < size; i++)
    {
        if (first)
            cout << array[i];
        else
            cout << ", " << array[i];
        first = false;
    }

    cout << " ]\n";
}

int main()
{
    uint size;
    cout << "How many integers in this array?";
    cin >> size;

    int * array = new int[size];
    for(uint i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1<< ": ";
        cin >> array[i];
    }


    //first draft
    int * prodArray = createProductArray(array, size);
    cout << "Product Array w/o division: ";
    displayList(prodArray, size);
    delete [] prodArray;

    //optimized a bit more with division.
    prodArray = createProductArrayUsingDivision(array, size);
    cout << "Product Array with division: ";
    displayList(prodArray, size);

    //clean up the mess
    delete [] array;
    delete [] prodArray;
}