
#include <iostream>
#include <stack>

std::string findLongestFilePath(std::string directory)
{
    size_t EOL;
    std::size_t newEnd;
    unsigned int dirsDeep = 0;
    unsigned int dirsDeepBefore = 0;
    std::string dirSoFar = "";
    std::string longestDirSoFar = "";
    std::string nextFile = "";
    while(!directory.empty())
    {   
     
        EOL = directory.find("\\n");
        nextFile = directory.substr(0, EOL);
        dirsDeep = 0;

        if(EOL == std::string::npos)
        {
            directory = "";
        }
        else
        {
            directory = directory.substr(EOL + 2);
        }

        while(nextFile.find("\\t") == 0)
        {
            dirsDeep++;
            nextFile = nextFile.substr(2);
        }

        if(dirsDeep < dirsDeepBefore)
        {
            newEnd = dirSoFar.find_last_of("/");
            dirSoFar = dirSoFar.substr(0, newEnd);

            unsigned int stepsBack = 0;
            while(dirsDeep != dirsDeepBefore - stepsBack)
            {
                newEnd = dirSoFar.find_last_of("/");
                dirSoFar = dirSoFar.substr(0, newEnd);
                stepsBack++;
            }

            dirSoFar += "/" + nextFile;
            
        }

        else if(dirsDeep == dirsDeepBefore || dirsDeep == dirsDeepBefore + 1)
        {
            if(dirsDeep == dirsDeepBefore)
            {
                newEnd = dirSoFar.find_last_of("/");
                dirSoFar = dirSoFar.substr(0, newEnd);
            }
            dirSoFar += "/" + nextFile;
            if(dirSoFar.size() > longestDirSoFar.size())
            {
                longestDirSoFar = dirSoFar;   
            }
        }
        else
        {
            std::cout << "Something went wrong. Your file directory system does not make sense.\n";
            return "";
        }
        
        dirsDeepBefore = dirsDeep;        
    }

    return longestDirSoFar;
    
}

int main()
{   
    std::string directoryString;
    std::cout << "Please enter a directory string to parse (use \\n and \\t for newlines/tabs): ";
    std::cin >> directoryString;

    std::string longestFilePath = findLongestFilePath(directoryString);
    std::cout << "The longest file path is: " <<  longestFilePath << "\n";
    std::cout << "It is " << longestFilePath.size() << " characters in length.\n";


}