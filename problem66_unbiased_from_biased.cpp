#include <iostream>
#include <random>
#include <ctime>

int biased_coin()
{
    const static int biased = rand() % 99 + 1;

    int randomInt = rand() % 100;
    if(randomInt > biased)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int unbiased_coin()
{
    int a = biased_coin();
    int b = biased_coin();

    if(a == 1 && b == 0)
    {
        return 1;
    }

    if(a == 0 && b == 1)
    {
        return 0;
    }

    return unbiased_coin();
}
int main()
{
    srand(time(NULL));
    int heads = 0;
    int tails = 0;
    bool isHeads;
    for(int i = 0; i < 100000000; i++)
    {
        isHeads = biased_coin();
        if(isHeads)
        {
            heads++;
        }
        else
        {
            tails++;
        } 
    }
    std::cout << "Biased coin heads = " << heads / 1000000.0 << "%\n";
    std::cout << "Biased coin tails = " << tails / 1000000.0 << "%\n";

    heads = 0;
    tails = 0;

    for(int i = 0; i < 100000000; i++)
    {
        isHeads = unbiased_coin();
        if(isHeads)
        {
            heads++;
        }
        else
        {
            tails++;
        }
    }

    std::cout << "Unbiased coin heads = " << heads / 1000000.0 << "%\n";
    std::cout << "Unbiased coin tails = " << tails / 1000000.0 << "%\n";
}