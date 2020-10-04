/*This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
 For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr. 

NOTE: It appears the example was written in python, but I chose to contine writing in c++;
*/
#include <map>
#include <iostream>
using std::pair;
using std::cin;
using std::cout;
std::pair <int, int> cons(int a, int b)
{
    return std::pair<int, int> (a,b);
}

int car(std::pair <int, int> p)
{
    return p.first;
}

int cdr(std::pair <int, int> p)
{
    return p.second;
}

int main()
{
    int x, y;
    cout << "Please enter the left side of your pair: ";
    cin >> x;
    cout << "Please enter the right side of your pair: ";
    cin >> y;

    cout << "\n";

    cout << "The left side is: " << car(cons(x, y)) << "\n";
    cout << "The right side is : " << cdr(cons(x, y)) << "\n";
}