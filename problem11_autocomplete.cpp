
/*
This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a 
set of all possible query strings, return all strings in the set that 
have s as a prefix.

For example, given the query string de and the set of strings 
[dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

NOTE: I read in a dictionary.txt file. This gives a very large list of possible words because
the dictionary is very large (over 300,000 words). 
*/
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
        word[0] = tolower(word[0]); //lowercase first letter
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