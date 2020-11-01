#include <vector>
#include <iostream>
typedef std::vector <std::vector <bool> > vectorBool2D;
typedef std::pair <unsigned int, unsigned int> indexPair;


unsigned int computeShortestPath(vectorBool2D maze, indexPair start, indexPair end)
{
    std::vector<unsigned int> shortestPathsFound(maze.size() * maze[0].size(), UINT_MAX);
    std::vector<unsigned int> possiblePaths(maze.size() * maze[0].size(), UINT_MAX);
    unsigned int startIndex = start.first * maze[0].size() + start.second;
    unsigned int endIndex = end.first * maze[0].size() + end.second;
    possiblePaths[startIndex] = 0;
    int pause;
    indexPair currentPos;
    unsigned int saveSmallest;
    unsigned int currentPosInd;
    while(shortestPathsFound[endIndex] == UINT_MAX)
    {
        saveSmallest = UINT_MAX;
        for(int findShort = 0; findShort < possiblePaths.size(); findShort++)
        {
            if(possiblePaths[findShort] < saveSmallest && shortestPathsFound[findShort] == UINT_MAX)
            {
                saveSmallest = possiblePaths[findShort];
                currentPos.first = findShort / maze[0].size();
                currentPos.second = findShort % maze[0].size();
                currentPosInd = findShort;
            }
        }

        shortestPathsFound[currentPosInd] =  saveSmallest;

        if(currentPos.first != 0 && maze[currentPos.first - 1][currentPos.second] == false)
        {
            possiblePaths[(currentPos.first - 1) * maze[0].size() + currentPos.second] = saveSmallest + 1;
        } 

        if(currentPos.first != maze.size() - 1 && maze[currentPos.first + 1][currentPos.second] == false)
        {
            possiblePaths[(currentPos.first + 1) * maze[0].size() + currentPos.second] = saveSmallest + 1;
        } 

        if(currentPos.second != 0 && maze[currentPos.first][currentPos.second - 1] == false)
        {
            possiblePaths[currentPos.first * maze[0].size() + currentPos.second - 1] = saveSmallest + 1;
        }

        if(currentPos.second != maze[0].size() && maze[currentPos.first][currentPos.second + 1] == false)
        {
            possiblePaths[currentPos.first * maze[0].size() + currentPos.second + 1] = saveSmallest + 1;
        }
        
    }

    return shortestPathsFound[endIndex];

}

int main()
{
    vectorBool2D maze;
    std::vector<bool> falseVec(4, false);
    std::vector<bool> wallWithDoor(4, true);
    wallWithDoor[2] = false;

    maze.push_back(falseVec);       // E F F F (E = end)
    maze.push_back(wallWithDoor);   // T T F T
    maze.push_back(falseVec);       // F F F F
    maze.push_back(falseVec);       // S F F F (S = start)

    indexPair start(3, 0);
    indexPair end(0, 0);

    std::cout << "The shortest distance from start to end is " << computeShortestPath(maze, start, end) << "\n";

}