/*****************************************************************************
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by LinkedIn.
 *
 * Given a list of points, a central point, and an integer k, find the nearest
 * k points from the central point.
 *
 * For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central
 * point (1, 2), and k = 2, return [(0, 0), (3, 1)].
 * 
 * 
 * Compiled and tested using g++ and c++11
 *****************************************************************************/

#include <set>
#include <cmath>
#include <iostream>
#include <random>

std::set<std::pair<double, double> > compute_closest_point_from_central_point(std::set<std::pair<double, double> > points, std::pair<double, double> center)
{
  std::set<std::pair<double, double> > result;

  if (points.size() > 0)
  {
    double smallestXDist = INFINITY;
    double smallestYDist = INFINITY;

    for (std::pair<double, double> point : points)
    {
      double xDist = abs(center.first - point.first);
      double yDist = abs(center.second - point.second);

      // Save some CPU time here. If this is the smallest x distance and y distance
      if (xDist < smallestXDist && yDist < smallestYDist)
      {
        smallestXDist = xDist;
        smallestYDist = yDist;
        result.clear();
        result.insert(point);
      }
      else if (xDist == smallestXDist && yDist == smallestYDist)
      {
        result.insert(point);
      }
      else // We must compute the distance at this point
      {
        double xSquared = (xDist * xDist);
        double ySquared = (yDist * yDist);
        double oldXSquared = (smallestXDist * smallestXDist);
        double oldYSquared = (smallestYDist * smallestYDist);
        double distance = sqrt(xSquared + ySquared);
        double oldDistance = sqrt(oldXSquared + oldYSquared);

        if (distance < oldDistance)
        {
          smallestXDist = xDist;
          smallestYDist = yDist;
          result.clear();
          result.insert(point);
        }
        else if (distance == oldDistance)
        {
          result.insert(point);
        }
      }
    }
  }

  return result;
}

void displaySet(const std::set<std::pair<double, double> > & setToDisplay)
{
  std::cout << "{";
  bool firstTime = true;

  for(auto doublePair : setToDisplay)
  {
    if(firstTime == false)
    {
      std::cout << ", ";
    }
    firstTime = false;
    std::cout << "{" << doublePair.first << ", " << doublePair.second << "}";
  }
  std::cout << "}";
}

void printResult(const std::set<std::pair<double, double> > &pointSet, const std::pair<double, double> &center, const std::set<std::pair<double, double> > &resultSet)
{
  // Display givens
  std::cout << "Provided the set of points: ";
  displaySet(pointSet);
  std::cout << ",\n";
  std::cout << "and provided the center: {" << center.first << ", " << center.second << "}\n";

  // Display result
  std::cout << "The closest points is/are: ";
  displaySet(resultSet);
  std::cout << "\n";
}

void providedExample()
{
  std::set<std::pair<double, double> > providedSet;
  std::pair<double, double> point0(0, 0);
  std::pair<double, double> point1(5, 4);
  std::pair<double, double> point2(3, 1);
  providedSet.insert(point0);
  providedSet.insert(point1);
  providedSet.insert(point2);
  std::pair<double, double> providedCenter(1, 2);
  std::set<std::pair<double, double> > providedResult;
  providedResult = compute_closest_point_from_central_point(providedSet, providedCenter);
  printResult(providedSet, providedCenter, providedResult);
}

void example(unsigned int count)
{
  srand(time(NULL));

  std::set<std::pair<double, double> > providedSet;
  std::pair<double, double> point;
  for (unsigned int c = 0; c < count; c++)
  {
    point.first = (rand() % 10000) / 100.0;
    point.second = (rand() % 10000) / 100.0;
    providedSet.insert(point);
  }
  std::pair<double, double> providedCenter((rand() % 10000) / 100.0, (rand() % 10000) / 100.0);

  std::set<std::pair<double, double> > providedResult;
  providedResult = compute_closest_point_from_central_point(providedSet, providedCenter);
  printResult(providedSet, providedCenter, providedResult);
}

int main()
{
  providedExample();
  example(10);
  example(1000000);
}