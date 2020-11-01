#include <vector>
#include <string>
#include <iostream>
std::string finalizeJustifiedVector(std::vector<std::string> wordsToCombine, unsigned int counter, unsigned int num)
{
    std::string retVal = "";
    unsigned int numGaps = (wordsToCombine.size() == 1 ?  1 : wordsToCombine.size() - 1);
    unsigned int numExtraSpaces = num - counter;
    unsigned int averageSpacePerGap = numExtraSpaces / numGaps + 1;
    unsigned int extraSpaces = numExtraSpaces % numGaps;
    std::string averageSpaces = std::string(averageSpacePerGap, ' ');
    for(unsigned int i = 0; i < wordsToCombine.size(); i++)
    {
        retVal += wordsToCombine[i];
        if(i + 1 < wordsToCombine.size())
        {
            retVal += averageSpaces;
            if(i < extraSpaces)
            {
                retVal.push_back(' '); //extra spaces on the left.
            }
        }
    }

    return retVal;
}
std::vector<std::string> justifyStringList(std::vector<std::string> list, unsigned int num)
{
    int lastCount = 0;
    int counter = 0;
    std::string justText;
    std::vector<std::string> justifiedText;
    std::vector<std::string> tempLine;
    for(int i = 0; i < list.size(); i++)
    {
        counter += list[i].size() + 1;
        //counter - 1 because a space is not needed on the end...

        if(counter - 1 > num)
        {
            counter -= (list[i].size() + 2); //remove the extra word and 2 spaces at the end.
            if(counter < 0)
            {
                counter = list[i].size();
                tempLine.push_back(list[i]);
                i++;
            }
            justText = finalizeJustifiedVector(tempLine, counter, num);
            justifiedText.push_back(justText);
            tempLine.clear();
            counter = 0;
            i--; //redo the most recent word.
        }
        else if(counter - 1 == num)
        {
            tempLine.push_back(list[i]);
            counter--;
            justText = finalizeJustifiedVector(tempLine, counter, num);
            justifiedText.push_back(justText);
            tempLine.clear();
            counter = 0;

        }
        else if(counter - 1 < num)
        {
            tempLine.push_back(list[i]);
        }
        
    }
    
    if(counter > 0)
    {
        justifiedText.push_back(finalizeJustifiedVector(tempLine, counter - 1, num));
    }

    return justifiedText;
}

void displayVector(std::vector<std::string> words)
{
    for(int i = 0; i < words.size(); i++)
    {
        std::cout << words[i] << "\n";
    }
}

int main()
{
    std::vector<std::string> words;

    words.push_back("the");
    words.push_back("quick");
    words.push_back("brown");
    words.push_back("fox");
    words.push_back("jumps");
    words.push_back("over");
    words.push_back("the");
    words.push_back("lazy");
    words.push_back("dog");

    int justifySize = 18;

    words = justifyStringList(words, justifySize);
    displayVector(words);

}