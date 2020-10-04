#include <iostream>
#include <set>
using std::cout;
using std::cin;
void displaySet(std::string equals, std::set<int> indexes)
{
    std::cout << equals;
    bool first = true;
    for(std::set<int>::iterator it = indexes.begin(); it != indexes.end(); it++)
    {
        if(first)
        {
            std::cout << "a[" << *it << "] ";
            first =false;
        }
        else
        {
            std::cout << "+ a[" << *it << "] ";
        }
    }
}

double computeNonAdjSum(double * array, uint size)
{
    double incl = array[0];
    double excl = 0;
    double temp;
    for(int i = 1; i < size; i++)
    {
        
        temp = incl;
        incl = excl + array[i];  
        if(temp > excl)
        {
            excl = temp;
        }
        
    }

    if(incl > excl)
    {
        return incl;
    }
    else
    {
        return excl;
    }
    
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

    cout << "The largest non-adjacent sum is " << computeNonAdjSum(array, size);
}
