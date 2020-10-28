#include <iostream>

using namespace std;
int swapBits(int x)
{
    return (((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1));
}
int main()
{
    int x;
    std::cout << "Please enter an integer you would like to swap even and odd bits: ";
    std::cin >> x;
    
    std::cout << "The result is " << swapBits(x) << std::endl;

    return 0;
}