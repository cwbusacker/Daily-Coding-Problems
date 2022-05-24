
/************************************************************************
 * This problem was asked by Google.
 * 
 * A girl is walking along an apple orchard with a bag in each hand. She 
 * likes to pick apples from each tree as she goes along, but is 
 * meticulous about not putting different kinds of apples in the same bag.
 *
 * Given an input describing the types of apples she will pass on her 
 * path, in order, determine the length of the longest portion of her
 *  path that consists of just two types of apple trees.
 *
 * For example, given the input [2, 1, 2, 3, 3, 1, 3, 5], the longest 
 * portion will involve types 1 and 3, with a length of four.
 *
 *
 * NOTE: I decided to make the code more reusable by creating a function
 * that could be based on any number of types passed (i.e. The girl now
 * is willing to walk passed 4 types)
 ************************************************************************/
#include <vector>
#include <map>
#include <iostream>

int computeLongestPath(std::vector<int> path, const unsigned int numTypes)
{
  std::map<int, int> typesPassed;
  unsigned int pass1 = 0;
  unsigned int pass2 = 0;
  unsigned int pathLength = 0;
  unsigned int maxPath = 0;
  while(pass1 < path.size())
  {
    // Haven't passed this number yet in our current path
    if(typesPassed.count(path[pass1]) == 0)
    {
      // We are allowed to add another type to our longest path
      if(typesPassed.size() < numTypes)
      {
        typesPassed[path[pass1]] = 1;
        pathLength++;
        pass1++;
      }
      // We are not allowed to add another type, so using pass2, remove and count down
      // from the rear
      else
      {
        // Before we delete, check if we had the longest path so far...
        if(pathLength > maxPath)
          maxPath = pathLength;

        // Remove while the typesPassed is equal to the number of Types
        while(typesPassed.size() == numTypes)
        {
          typesPassed[path[pass2]]--;
          if(typesPassed[path[pass2]] == 0)
          {
            typesPassed.erase(typesPassed.find(path[pass2]));
          }
          pathLength--;
          pass2++;
        }
      }
    }
    else // Already passed this number in our current path, just increment the 
         // number of times we've passed it, add one to our path and take the next step
    {
      typesPassed[path[pass1]]++;
      pathLength++;
      pass1++;
    }
  }

  // Check the last path we made to see if it is the longest path
  if(pathLength > maxPath)
    maxPath = pathLength;

  return maxPath;
}

int main()
{
  int array[] = {2, 1, 2, 3, 3, 1, 3, 5};
  std::vector<int> path;
  
  for(unsigned int i = 0; i < 8; i++)
  {
    path.push_back(array[i]);
  }

  int maxTypes = 2;

  std::cout << "The longest path with only 2 types of apples is: " 
            << computeLongestPath(path, maxTypes) << "\n";

  return 0;
}