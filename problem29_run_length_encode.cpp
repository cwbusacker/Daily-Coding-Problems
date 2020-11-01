#include <string>
#include <iostream>

std::string computeRunLengthEncoding(std::string word)
{
    unsigned int size = word.size();
    std::string retVal = "";
    std::string countStr;
    char currentChar = word[0];
    int count = 1;
    for(int i = 1; i < size; i++)
    {
        if(currentChar == word[i])
        {
            count++;
        }
        else
        {
            countStr = std::to_string(count);
            retVal += countStr;
            retVal.push_back(word[i - 1]);

            currentChar = word[i];
            count = 1;

        }
        
    }
    return retVal;
}

int main()
{
    std::string testMe = "aaaAAABBBBBBBCCCDDDDDDDFFKFJ";
    std::string result = computeRunLengthEncoding(testMe);
    std::cout << "The run-length encoded string of " << testMe << " is " << result << "\n";
}