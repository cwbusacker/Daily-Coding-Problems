/*

This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom 
lectures (possibly overlapping), find the minimum number 
of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/
#include <vector>
#include <algorithm>
#include <iostream>

int computeMinRoomsNeeded(std::vector<std::pair<int, int> > meetingTimePairs, unsigned int bufferTime = 0)
{
    std::vector<int> startTimes;
    std::vector<int> endTimes;

    for(unsigned int i = 0; i < meetingTimePairs.size(); i++)
    {
        startTimes.push_back(meetingTimePairs[i].first);
        endTimes.push_back(meetingTimePairs[i].second);
    }

    std::sort(startTimes.begin(), startTimes.end());
    std::sort(endTimes.begin(), endTimes.end());

    int roomsNow = 0;
    int maxRoomsNeeded = 0;
    int startWalker = 0;
    int endWalker = 0;
    while(startWalker < startTimes.size() && endWalker < endTimes.size())
    {
        if(startTimes[startWalker] < endTimes[endWalker] + bufferTime)
        {
            //Need another room because another meeting has started
            roomsNow++;
            startWalker++;

            //have we exceeded the max amount of rooms so far?
            if(roomsNow > maxRoomsNeeded)
            {
                maxRoomsNeeded = roomsNow;
            }
        }
        else
        {
            endWalker++;
            roomsNow--;
        }        
    }

    return maxRoomsNeeded;
}

int main()
{
    std::vector<std::pair<int, int> > timePairs;
    std::pair<int, int> timePair;
    unsigned int meetings;
    std::cout << "How many meetings are there? ";
    std::cin >> meetings;

    for(int i = 0; i < meetings; i++)
    {
        std::cout << "Enter start time for meeting #" << i + 1 << ":";
        std::cin >> timePair.first;
        std::cout << "Enter end   time for meeting #" << i + 1 << ":";
        std::cin >> timePair.second;
        timePairs.push_back(timePair);
    }
    
    int buffer;
    std::cout << "How much buffer time do you want between meetings? ";
    std::cin >> buffer;

    int rooms = computeMinRoomsNeeded(timePairs, buffer);
    std::cout << "Your event will require a minimum of " << rooms << " rooms.\n";
}
