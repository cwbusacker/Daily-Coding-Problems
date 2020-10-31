
#include <vector>
#include <iostream>
int computeWaterUnitsTrapped(std::vector<unsigned int> wall)
{
    if(wall.size() < 3)
    {
        return 0; //need at least 3 walls to trap water (left, ground, right)
    }


    unsigned int retVal = 0;

    int hi = wall.size() - 1;
    int lo = 0;

    unsigned int maxLeft = 0;
    unsigned int maxRight = 0;

   while(lo <= hi)
   {
        //focus on the wall that is smaller
        if(wall[lo] < wall[hi])
        {
            //left side is smaller
            //check if it's bigger than the biggest
            //wall and if so, just save it off.
            if(wall[lo] > maxLeft)
            {
                maxLeft = wall[lo];
            }
            else 
            //otherwise, the biggest wall on the left 
            //will determine the amount of water than can be held
            //(since the wall on the far right is bigger)
            {
                retVal += maxLeft - wall[lo];
            }
            //this wall now matters not.
            lo++;
        }
        else //(see the left side for comments)
        {
            if(wall[hi] > maxRight)
            {
                maxRight = wall[hi];
            }
            else
            {
                retVal += maxRight - wall[hi];
            }

            hi--;
        }
    }

    return retVal;
}


int main()
{
    std::vector<unsigned int> wall;
    wall.push_back(1);   //0
    wall.push_back(1);   //0
    wall.push_back(10);  //0
    wall.push_back(1);   //9
    wall.push_back(100); //0
    wall.push_back(1);   //99
    wall.push_back(1000);//0
    wall.push_back(1);   //99
    wall.push_back(100); //0
    wall.push_back(1);   //9
    wall.push_back(10);  //0
    wall.push_back(1);   //0
    wall.push_back(1);   //0

    int units = computeWaterUnitsTrapped(wall); //216
    std::cout << "Total Units Trapped: " << units << "\n"; 

}