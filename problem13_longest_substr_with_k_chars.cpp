

/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void setAll(unsigned int * array, const unsigned int & size, const unsigned int & value )
{
    //sets an entire array to value
    for(int i = 0; i < size; i++)
    {
        array[i] = value;
    }
}
string findSubstrWithOnlyKRepeats(string searchMe, unsigned int k)
{
    unsigned int startIndex = 0;
    unsigned int longestLength = 0;
    unsigned int lengthSoFar = 0;
    unsigned int size = searchMe.size();
    unsigned int repeats[256];

    //this is the part where we search for the biggest substring
    for(int i = 0; i < size; i++)
    {
        setAll(repeats, 256, 0);
        //start the search over again.
        lengthSoFar = 0;
        for(int j = i; j < size; j++)
        {
            //increment repeats and length
            repeats[searchMe[j]]++;
            lengthSoFar++;
            //keep track of each char. Each char has its
            //own index in repeat.
            if(repeats[searchMe[j]] > k || j + 1 == size)
            {  
                
                if(lengthSoFar > longestLength)
                {
                    //found  a larger string
                    longestLength = lengthSoFar;
                    startIndex = i;
                }

                if(j + 1 == size)
                {
                    //if we've reached the end, then it's only going to
                    //get shorter from here on out, so return the result.
                     return searchMe.substr(startIndex, lengthSoFar);
                }
                
                //move i so that it will start passed the repeat "culprit"
                i = searchMe.find(searchMe[j], i);
                break;
            }
        }
    }
     return searchMe.substr(startIndex, lengthSoFar);
}

int main()
{
    string searchStr = "";
    cout << "Please enter a string to search: ";
    std::getline(cin, searchStr);
    
    unsigned int k = 0;
    cout << "Please enter the max number of repeat letters to be found: ";
    cin >> k;
    string subStr = findSubstrWithOnlyKRepeats(searchStr, k);

    cout << "The longest substring with only " << k << " repeats of letters is: " << subStr << endl;
    
}