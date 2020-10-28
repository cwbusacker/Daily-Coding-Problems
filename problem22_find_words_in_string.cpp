#include <vector>
#include <string>
#include <iostream>
void displayVector(std::vector<std::string> vectorToDisplay)
{
    std::cout << "VECTOR: {";
    
    bool isFirst = true;
    for(unsigned int i = 0; i < vectorToDisplay.size(); i++)
    {
        if(isFirst)
        {
            std::cout << " " << vectorToDisplay[i];
            isFirst = false;
        }
        else
        {
           std::cout << ", " << vectorToDisplay[i];
        }
    }

    std::cout << " }\n";
}

std::vector<std::string> findWordsThatMakeUpString(std::vector<std::string> listOfWords, std::string fullWord)
{
    bool foundInRetList;
    std::vector<std::string> retVal;
    std::vector<std::string> undos;
    int stringIndex = 0;
    while(!fullWord.empty())
    {
        foundInRetList = false;
        for(unsigned int i = 0; i < retVal.size() && !foundInRetList; i++)
        {
            stringIndex = fullWord.find(retVal[i]);
            if(stringIndex == 0)
            {
                foundInRetList = true;
                undos.push_back(fullWord);
                fullWord = fullWord.substr(retVal[i].length());
            }
        }

        if(foundInRetList)
        {
            continue;
        }

        std::vector<std::string>::iterator it;
        for(it = listOfWords.begin(); it != listOfWords.end() && !foundInRetList;)
        {
            stringIndex = fullWord.find(*it);
            if(stringIndex == 0)
            {
                retVal.push_back(*it);
                foundInRetList = true;
                undos.push_back(fullWord);
                fullWord = fullWord.substr(it->length());
                it = listOfWords.erase(it);
            }
            else
            {
                it++;
            }
        }
        
        //This means we are stuck since we have not found any matches.
        //so we go back a step and try again, this time making the last attempt
        //a lower priority.
        if(!foundInRetList)
        {
            listOfWords.push_back(retVal.back());
            retVal.pop_back();
            fullWord = undos.back();
            undos.pop_back();
        }
            
        
    }

    return retVal;
}



int main()
{
    std::vector <std::string> bedBathVec;
    bedBathVec.push_back("bed");
    bedBathVec.push_back("bath");
    bedBathVec.push_back("bedbath");
    bedBathVec.push_back("and");
    bedBathVec.push_back("beyond");
    std::string bedBath = "bedbathandbeyond";
    std::vector <std::string> bedBathResult = findWordsThatMakeUpString(bedBathVec, bedBath);
    displayVector(bedBathResult);

    std::vector <std::string> theQuickVec;
    theQuickVec.push_back("the");
    theQuickVec.push_back("thequick");
    theQuickVec.push_back("brown");
    theQuickVec.push_back("fox");
    std::string theQuickStr = "thequickbrownfox";
    std::vector <std::string> theQuickResult = findWordsThatMakeUpString(theQuickVec, theQuickStr);
    displayVector(theQuickResult);

}