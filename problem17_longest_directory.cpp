/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a 
sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1
    \n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. 
subdir1 contains a file file1.ext and an empty second-level sub-directory 
subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 
containing a file file2.ext.
*/
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