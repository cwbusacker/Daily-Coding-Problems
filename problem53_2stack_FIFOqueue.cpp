#include <stack>
#include <iostream>
template <class T>
class queue
{
    public:
        queue() {}
        void enqueue(T data)
        {
            while(!stackTopFront.empty())
            {
                stackTopBack.push(stackTopFront.top());
                stackTopFront.pop();
            }
            stackTopBack.push(data);
        }

        T dequeue()
        {
            while(!stackTopBack.empty())
            {
                stackTopFront.push(stackTopBack.top());
                stackTopBack.pop();
            }
            T data = stackTopFront.top();
            stackTopFront.pop();
            return data;
        }

    private:

        std::stack<T> stackTopBack;
        std::stack<T> stackTopFront;
};


int main()
{
    queue<int> myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    std::cout << "Removing 1: " << myQueue.dequeue() << std::endl;
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);

    for(int i = 2; i <= 6; i++)
    {
        std::cout << "Removing " << i << ": " << myQueue.dequeue() << std::endl;
    }
}