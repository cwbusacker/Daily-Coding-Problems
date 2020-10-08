

/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

Note: I misunderstood the problem the first time. So, here is the redo. 
Note also that the first time was an attempt with only K repeats instead of distinct letters.
That code was left alone.
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

string findSubstrWithOnlyKDisticts(string searchMe, unsigned int k)
{
    unsigned int startIndex = 0;
    unsigned int longestLength = 0;
    unsigned int lengthSoFar = 0;
    unsigned int size = searchMe.size();
    unsigned int repeats[256];
    unsigned int distinctChars = 0;
    //this is the part where we search for the biggest substring
    for(int i = 0; i < size; i++)
    {
        //start the search over again.
        setAll(repeats, 256, 0);
        lengthSoFar = 0;
        distinctChars = 0;

        for(int j = i; j < size; j++)
        {
            
            //increment repeats and length
            repeats[searchMe[j]]++;
            if(repeats[searchMe[j]] == 1)
            {
                std::cout << "Found a new letter" << searchMe[j] << " that's " << distinctChars + 1 << "letters\n";
                distinctChars++;
            }
            lengthSoFar++;

            //keep track of each char. Each char has its
            //own index in repeat.
            if(distinctChars > k || j + 1 == size)
            { 
                
                if(lengthSoFar > longestLength)
                {
                    //found  a larger string
                    std::cout << "NEW LONGEST STRING: " << searchMe.substr(i, lengthSoFar - 1);
                    longestLength = lengthSoFar - 1;
                    startIndex = i;
                }

                if(j + 1 == size)
                {
                    //if we've reached the end, then it's only going to
                    //get shorter from here on out, so return the result.
                     return searchMe.substr(startIndex, longestLength);
                }

                //finding the next i, we can leave it at 1 because i++ will happen one more time
                //in the for loop increment section.
                while(repeats[searchMe[i]] > 1)
                {
                    repeats[searchMe[i]]--; 
                    i++;   
                }
                break;
            }
        }
    }
    return searchMe.substr(startIndex, longestLength);
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
                     return searchMe.substr(startIndex, longestLength);
                }
                
                //move i so that it will start passed the repeat "culprit"
                i = searchMe.find(searchMe[j], i);
                break;
            }
        }
    }
     return searchMe.substr(startIndex, longestLength);
}

int main()
{
    string searchStr = "";
    cout << "Please enter a string to search: ";
    std::getline(cin, searchStr);
    
    unsigned int k = 0;
    cout << "Please enter the max number of unique letters to be found: ";
    cin >> k;
    string subStr = findSubstrWithOnlyKDisticts(searchStr, k);

    cout << "The longest substring with only " << k << " unique letters is: " << subStr << endl;
    
}