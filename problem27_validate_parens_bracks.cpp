#include <stack>
#include <string>
#include <iostream>

bool validateOpenCloseBracketsParens(const std::string & bracketString)
{
    std::stack<char> opens;

    unsigned int size = bracketString.size();

    for(unsigned int i = 0; i < size; i++)
    {
        switch(bracketString[i])
        {
            case '(':
            case '{':
            case '[':
                opens.push(bracketString[i]);
                break;
            case ')':
                if(opens.empty() || opens.top() != '(')
                    return false;
                else
                    opens.pop();
                break;
            case '}':
                if(opens.empty() || opens.top() != '{')
                    return false;
                else
                    opens.pop();
                break;
            case ']':
                if(opens.empty() || opens.top() != '[')
                    return false;
                else
                    opens.pop();
                break;
            default:
                continue;


        }
    }

    return true;
}

int main()
{
    std::string valid = "[{}((())){{{}}}]";
    std::string invalid = "[][][][][][][][][][]]";

    if(validateOpenCloseBracketsParens(valid))
    {
        std::cout << "VALID STRING IS VALID.\n";
    }

    if(validateOpenCloseBracketsParens(invalid))
    {
        std::cout << "INVALID STRING IS VALID?\n";
    }


}