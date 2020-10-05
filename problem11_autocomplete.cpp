

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
std::map<char, std::vector<std::string> > readDictionary()
{
    std::map<char, std::vector<std::string> > retVal;
    std::string word;
    std::ifstream fileIn("dictionary.txt");
    while(std::getline(fileIn, word))
    {
        retVal[word[0]].push_back(word);
    }
    return retVal;
}

std::vector<std::string> computeAutoCompleteWords(std::string word)
{
    std::map<char, std::vector<std::string> > dictionary = readDictionary();
    std::vector<std::string> wordsThatStartWithFirstLetter = dictionary[word[0]];
    std::vector<std::string> retVal;
    unsigned int size = wordsThatStartWithFirstLetter.size();
    std::sort(wordsThatStartWithFirstLetter.begin(), wordsThatStartWithFirstLetter.end()); 
    if(word.length() == 1)
        return wordsThatStartWithFirstLetter;
    //is there a faster way? This is linear and slow
    bool foundFirstOne = false;
    for(unsigned int i = 0; i < size; i++)
    {
        if(wordsThatStartWithFirstLetter[i].find(word) == 0)
        {
            foundFirstOne = true;
            retVal.push_back(wordsThatStartWithFirstLetter[i]);
            continue;
        }
        //since these are sorted, once we found the first one
        //the next one that's doesn't start with the word,
        //means the rest are not included.
        if(foundFirstOne)
            break; 

    }

    return retVal;
}

int main()
{
    std::vector<std::string> possibleWords;
    std::string word;
    std::cout << "Please enter a partial word to auto-complete: ";
    std::cin >> word;

    possibleWords = computeAutoCompleteWords(word);
    unsigned int size = possibleWords.size();

    std::cout << "DID YOU MEAN ANY OF THESE WORDS?\n";
    for(unsigned int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << possibleWords[i] << "\n";
    }
}