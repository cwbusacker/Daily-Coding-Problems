#include <iostream>
template <class T>
class stack
{
    public:
        stack()
        {
            data = nullptr;
            numElements = 0;
        }

        T max()
        {
            return maxData;
        }

        void push(T val)
        {
            if(val > maxData)
            {
                maxData = val;
            }

            if(data == nullptr)
            {
                data = new T[1];
                numCapacity = 1;
            }
            else
            {
                realloc(numCapacity * 2);
            }
        
            data[numElements++] = val;
        }

        T pop()
        {
            if(numElements == 0)
            {
                throw "ERROR: Cannot pop on an empty stack";
            }
            numElements--;
            if(data[numElements] == maxData)
            {   
                maxData = findNewMax();
            }
            return data[numElements];
        }

        bool empty()
        {
            return numElements == 0;
        }
    private:
        void realloc(unsigned int newSize)
        {
            T * temp = new T[newSize];
            numCapacity = newSize;
            if(newSize < numElements)
            {
                numElements = newSize;
            }

            if(data)
            {
                for(int i = 0; i < numElements; i++)
                {
                    temp[i] = data[i];
                }
                delete [] data;
            }

            data = temp;
        }

        T findNewMax()
        {
            T newMax = data[0];
            for(int i = 1; i < numElements; i++)
            {
                if(data[i] > newMax)
                {
                    newMax = data[i];
                }
            }

            return newMax;
        }
        T * data;
        T maxData;
        unsigned int numElements;
        unsigned int numCapacity;
};

int main()
{
    stack<int> myStack;

    myStack.push(234);
    myStack.push(263);
    myStack.push(29802);
    myStack.push(-276);
    myStack.push(0);

    std::cout << "MAX: " << myStack.max() << std::endl;

    while(!myStack.empty())
    {
        std::cout << "Popped value: " << myStack.pop() << "\n";
        std::cout << "New Max: " << myStack.max() << "\n\n";
    }
}