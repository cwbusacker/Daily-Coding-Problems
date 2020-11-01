#include <random>
#include <ctime>
#include <iostream>

int rand5()
{
    return 1 + rand() % 5;
}

int rand7()
{
    int rand5to25 = rand5() + rand5() + rand5() + rand5() + rand5();

    return 1 + rand5to25 % 7;
}

int main()
{
    srand(time(NULL));

    int rand5arr[5] = {0, 0, 0, 0, 0};
    int rand7arr[7] = {0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 100000000; i++)
    {
        rand5arr[rand5() - 1]++;
        rand7arr[rand7() - 1]++;
    }

    std::cout << "Rand5() distribution:\n";
    for(int i = 0; i < 5; i++)
    {
        std::cout << i + 1 << ": " << rand5arr[i] / 1000000.0 << "%\n";
    }

    std::cout << "\nRand7() distribution:\n";
    for(int i = 0; i < 7; i++)
    {
        std::cout << i + 1 << ": " << rand7arr[i] / 1000000.0 << "%\n";
    }
}