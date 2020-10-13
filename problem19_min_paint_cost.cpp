
/*
This problem was asked by Facebook.

A builder is looking to build a row of N houses that can be of K different colors. 
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to 
build the nth house with kth color, return the minimum cost which achieves this goal.
*/

#include <iostream>
#include <vector>
#include <limits>
#define NUM_COLORS 6
#define MAX_HOUSES 10
const double COSTS[NUM_COLORS][MAX_HOUSES] =
{
    {134.34, 120.23, 175.12, 150.10, 256.12, 312.54,  99.50, 534.20, 123.12,  74.99}, //WHITE
    {174.35,  49.99,  49.99,  89.99,  56.99, 492.54,  89.54, 104.20, 212.12, 674.99}, //GREEN
    {134.34, 230.23, 179.18, 150.10, 156.12, 232.54, 154.59, 784.20, 121.22, 697.96}, //BLUE
    {154.34, 440.87, 188.28,  50.10, 356.12, 562.54, 263.54, 664.20, 333.32,  94.79}, //BROWN
    {174.34, 450.45, 197.19, 950.10, 556.12, 382.54, 372.51, 344.20, 212.12,  49.97}, //GRAY
    {114.34, 320.23, 106.52, 250.10, 156.12, 172.54, 481.59, 134.20, 121.22,  79.69}  //RED
};

const std::string names[NUM_COLORS] =
{
    "WHITE",
    "GREEN",
    "BLUE",
    "BROWN",
    "GRAY",
    "RED"
};

float computePaintHouseCost(const double costs[NUM_COLORS][MAX_HOUSES], int indexNum[], 
                        std::vector<std::string> & paintColors, int houseNum = 0, 
                                        int lastHouse = 10, int excludeColor = -1)
{
    double minCost = std::numeric_limits<double>::max();
    double tempCost = 0;
    unsigned int saveColor;
    std::vector <std::string> tempColors;
    std::vector <std::string> bestColors;
    std::vector<std::string> colorsSoFar = paintColors;
    if(houseNum == lastHouse)
    {
        return 0;
    }
    unsigned int size = paintColors.size();
    for(int i = 0; i < NUM_COLORS; i++)
    {
        if(i == excludeColor)
            continue;

        indexNum[i]++;
        tempCost = COSTS[i][indexNum[i]] + computePaintHouseCost(costs, indexNum, tempColors, 
                                                       houseNum + 1, lastHouse, i);
        indexNum[i]--;
        if(tempCost < minCost)
        {   
            bestColors.clear();
            bestColors.insert(bestColors.end(), colorsSoFar.begin(), colorsSoFar.end());
            bestColors.insert(bestColors.end(), tempColors.begin(), tempColors.end());
            bestColors.push_back(names[i]);
            minCost = tempCost;
            saveColor = i;
        }
        tempColors.clear();
    }
    
    paintColors = bestColors;
    return minCost;
    
}


int main()
{
    //one problem with this is that we are ONLY choosing the cheapest next step,
    //not the cheapest overall
    int indexNum[NUM_COLORS] = {0,0,0,0,0,0};
    std::vector<std::string> paintColors;
    double cost = computePaintHouseCost(COSTS, indexNum, paintColors);
    std::cout << "The minimum cost to paint 10 houses is $" << cost << std::endl; 
    std::cout << "To minimize costs, paint the houses in the following order:\n";
    for(std::vector<std::string>::reverse_iterator it = paintColors.rbegin(); 
            it != paintColors.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
}