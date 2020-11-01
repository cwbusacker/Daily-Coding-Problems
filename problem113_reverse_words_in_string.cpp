#include <string>
#include <stack>
#include <iostream>
std::string reverseWords(std::string phrase)
{
    int size = phrase.size();
    std::string retVal = "";
    std::stack<std::string> words;
    std::string tempStr;
    int i = 0;
    while(i < size)
    {
        if(phrase[i] != ' ')
        {
            tempStr += phrase[i];
        }
        else
        {
            words.push(tempStr);
            tempStr = "";
        }
        i++;
    }

    words.push(tempStr);

    while(!words.empty())
    {
        retVal += words.top();
        words.pop();
        if(!words.empty())
        {
            retVal += " ";
        }
    }
    
    return retVal;
}
std::string reverseWordsInPlace(std::string phrase)
{
    unsigned int size = phrase.size();
    unsigned int beginWord;
    unsigned int endWord;
    char temp;
    for(unsigned int i = 0; i < size; i++)
    {
        beginWord = i;
        while(i < size && phrase[i] != ' ')
            i++;

        endWord = i - 1;

        while(beginWord < endWord)
        {
            temp = phrase[endWord];
            phrase[endWord] = phrase[beginWord];
            phrase[beginWord] = temp;
            beginWord++;
            endWord--;
        }
    }

    beginWord = 0;
    endWord = size - 1;
    while(beginWord < endWord)
    {
        temp = phrase[endWord];
        phrase[endWord] = phrase[beginWord];
        phrase[beginWord] = temp;
        beginWord++;
        endWord--;
    }
    return phrase;
}
int main()
{
    std::string hello = "Hello world! how are you";
    std::string flipped = reverseWordsInPlace(hello);
    std::cout << flipped << std::endl;
}