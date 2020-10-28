#include <string>
#include <iostream>
struct Regex_match
{
    Regex_match()
    {
        results = nullptr;
        numResults = 0;
    }

    void clear()
    {
        if(results)
        {
            delete [] results;
        }

        results = nullptr;
    }

    std::string operator[] (unsigned int index)
    {
        if(index >= numResults || index < 0)
            throw "Regex_match::operator[] ERROR: index out of range.";
        return results[index];
    }

    unsigned int size()
    {
        return numResults;
    }
    bool add(std::string newstring)
    {
        numResults++;
        if(results == nullptr)
        {
            results = new std::string[numResults];
            results[0] = newstring;
            return true;
        }
        else
        {
            std::string * temp = new std::string[numResults];
            for(int i = 0; i < numResults - 1; i++)
            {
                temp[i] = results[i];
            }
            temp[numResults - 1] = newstring;
            delete [] results;
            results = temp;
        }
        
        return true;
    }

    std::string * results;
    unsigned int numResults;
};
class Regex
{
    public:
        Regex(const char * regex) :regularExpression(regex)
        {
        }

        Regex(const std::string & regex)
        {
            this->regularExpression = regex;
        }

        void setRegex(const char * regex)
        {   

        }   

        void setRegex(const std::string & regex)
        {
            this->regularExpression = regex;
        }

        bool compare(std::string testStr, Regex_match & rem)
        {
            rem.clear();

            bool isGroup = false;
            bool isCollection = false;
            std::string saveMe = testStr;
            rem.add(testStr);

            unsigned int j = 0;
            char c;
            for(unsigned int i = 0; j < regularExpression.size(); i++, j++)
            {
                if(isGroup && regularExpression[j] != ')')
                {
                    saveMe.push_back(testStr[i]);
                }
                switch(regularExpression[j])
                {
                    case '.':
                        break;

                    case '*':
                        c = regularExpression[j - 1];
                        if(c == '.')
                        {
                            while(testStr[i] != '\n' && testStr[i] != '\r' && testStr[i] != '\0')
                            {
                                if(isGroup) saveMe.push_back(testStr[i]);
                                i++;
                            }
                            i--;
                        }
                        else
                        {
                           while(testStr[i] == c)
                           {
                               if(isGroup) saveMe.push_back(c);
                               i++;
                           }
                            i--;
                        }
                        break;
                    
                    case '(':
                        isGroup = true;
                        saveMe = "";
                        i--;
                        break;
                    case ')':
                        rem.add(saveMe);
                        isGroup = false;
                        i--;
                        break;
                    default:
                        if(testStr[i] != regularExpression[j] && regularExpression[j + 1] != '?')
                        {
                            std::cout << "UH oH..\"" << testStr[i] << "\" does not equal \"" << regularExpression[j] <<"\"" << std::endl;
                            rem.clear();
                            return false;
                        }
                        else if(regularExpression[j + 1] == '?')
                        {
                            j += 2;
                            i--; //neutralize the i++ in the loop.
                        }
                        
                }
            }

            return true;
        }
    private:
        std::string regularExpression;
};

int main()
{
    Regex_match rem;
    Regex regex("(Hel*o) (world)(.*)");

    bool result = regex.compare("Hellllllllllo world;laksjdf;lkajsdf;lkajsdf", rem);

    if(result)
    {
        std::cout << "The string matches the regex.\n";
    }

    else
    {
        std::cout << "The string does not match the regex.\n";
    }

    std::cout << "The groupings are:\n";

    for(unsigned int i = 0; i < rem.size(); i++)
    {
        std::cout << rem[i] << "\n";
    }
    
}