/*

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, 
which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) which 
returns the node at index.

*/
#include <stdint.h>
#define nullptr 0 //because macOS doesn't have nullptr
template <class T>
class XorList
{
    
    class Node
    {
        public:
            Node(T data, Node * p1 = nullptr, Node * p2 = nullptr)
            {
                value = data;
                nxtAndPrev = XOR(p1, p2);
            }

            Node * next(Node * prev)
            {
               return XOR(nxtAndPrev, prev);
            }

            Node * prev(Node * next)
            {
                return XOR(nxtAndPrev, next);
            }

            void updatePointer(Node * next)
            {
                //currently one pointer is already set;
                nxtAndPrev = XOR(nxtAndPrev, next);
            }

            void setPointer(Node * prev, Node * next)
            {
                nxtAndPrev = XOR(prev, next);
            }
            T getData()
            {
                return value;
            }

            void setData(T data)
            {
                value = data;
            }
            
            Node * XOR(Node * p, Node * n)
            {
               return (Node *)((uintptr_t)(p) ^ (uintptr_t)(n));
            }
        private:
            
             T value;
            Node * nxtAndPrev;
    };

    Node * pHead;
    Node * pTail;

    public:
        XorList()
        {
            pHead = nullptr;
            pTail = nullptr;
        }

        XorList(T data)
        {
            pHead = new Node(data);
            pTail = pHead;
        }

        void add_to_end(T data)
        {
            if(pHead == nullptr)
            {
                pHead = new Node(data);
                return;
            }
            
            Node * node = new Node(data, pTail);
            pTail->updatePointer(node);
            pTail = node;
        }

        T operator [] (unsigned int index)
        {
            Node * node = pHead;
            Node * prev = nullptr;
            Node * next = nullptr;
            for(unsigned int i = 0; i < index && node != nullptr; i++)
            {
                next = node->next(prev);
                prev = node; 
                node = next;
            }
            if(index >= 0 && node)
            {
                return node->getData();
            }
            else
            {
                throw "ERROR: Invalid XorLinkedList::operator[] was given an invalid index\n";
            } 
        }

        Node * get(unsigned int index)
        {
            Node * node = pHead;
            Node * prev = nullptr;
            Node * next = nullptr;
            for(unsigned int i = 0; i < index && node != nullptr; i++)
            {
                next = node->next(prev);
                prev = node; 
                node = next;
            }
            if(index >= 0 && node)
            {
                return node;
            }
            else
            {
                throw "ERROR: Invalid XorLinkedList::operator[] was given an invalid index\n";
            } 
        }

        Node * getPreviousNode(Node * findMe)
        {
            Node * node = pHead;
            Node * prev = nullptr;
            Node * next = nullptr;
            for(unsigned int i = 0; node != nullptr; i++)
            {
                next = node->next(prev);
                prev = node; 
                node = next;
                if(findMe == node)
                {
                    return prev;
                }
            }

            return nullptr;
        }
        /*One problem with this data structure: it is complicated to insert in the middle. :( */
        void insert(T data, Node * insertAfterMe = nullptr)
        {
            Node * newNode = new Node(data);
            Node * prev = getPreviousNode(insertAfterMe);
            Node * insertBeforeMe = insertAfterMe->next(prev);

            insertAfterMe->setPointer(prev, newNode);
            newNode->setPointer(insertBeforeMe, insertAfterMe);
            insertBeforeMe->setPointer(newNode, insertBeforeMe->next(insertAfterMe));
        }
};


#include <iostream>
#include <stdexcept>
using std::cout;
int main()
{
    XorList<int> list (1);
    list.add_to_end(2);
    list.add_to_end(3);
    list.add_to_end(5);

    list.insert(4, list.get(2));

    //should display { 1 2 3 4 5 }
    cout << "{ ";
    for(int i = 0; i < 5; i++)
    {
        cout << list[i] << " ";
    }
    cout << "}\n";


    //test if given an invalid index.
    try
    {
        cout << list[6];
    }
    catch(const char * e)
    {
        std::cerr << e;
    }
    
}