/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.
*/
#include <iostream>
class OrderData
{
    unsigned int * list;
    unsigned int cap;
    unsigned int numElems;

    public:
        OrderData()
        {
            list = nullptr;
            cap = 0;
            numElems = 0;
        }
        void record(unsigned int order_id)
        {
            if(cap == 0)
            {
                realloc(1);
            }
            else if(cap == numElems)
            {
                realloc(cap * 2);
            }

            list[numElems++] = order_id;
        }
        unsigned int getLast()
        {
            if(numElems == 0)
            {
                throw "There are no order ids.";
            }
            
            return list[numElems - 1];
        }

    private:
        void realloc(unsigned int newSize)
        {
            if(newSize <= 0 && list != nullptr)
            {
                delete [] list;
                numElems = 0;
                cap = 0;
            }

            unsigned int * newlist = new unsigned int[newSize];
            
            if(numElems != 0 && list != nullptr)
            {
                for(unsigned int i = 0; i < numElems; i++)
                {
                    newlist[i] = list[i];
                }
            }

            delete [] list;
            cap = newSize;
            list = newlist;
        }
};

int main()
{
    OrderData orders;
    unsigned int order_id = 1;
    std::cout << "Add order ids to the list. Enter 0 when done.\n";
    while(order_id)
    {
        std::cout << "Enter an id: ";
        std::cin >> order_id;
        if(order_id != 0)
        {
            orders.record(order_id);
        }
    }

    std::cout << "The last id recorded was: " << orders.getLast() << std::endl;


}