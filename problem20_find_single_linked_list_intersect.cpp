/*
This problem was asked by Google.

Given two singly linked lists that intersect at some point, 
find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, 
return the node with value 8.

In this example, assume nodes with the same value are the exact 
same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) 
and constant space.
*/
#include <iostream>
template <class T>
class Node
{
    public:
        Node(T data) {this-> data = data; }
        Node<T> * pNext;
        T data;
};

template <class T>
unsigned int listLength(Node<T> * pHead)
{
    unsigned int result = 0;
    while(pHead)
    {
        pHead = pHead->pNext;
        result++;
    }
    return result;
}

template <class T>
Node<T> * reverseList(Node<T> * pHead, Node<T> * pPrev = NULL)
{
    if(pHead->pNext == NULL)
    {
        pHead->pNext = pPrev;
        return pHead; //return the tail all the way back
    }
    Node<T> * pNext = pHead->pNext;
    pHead->pNext = pPrev;
    return reverseList(pNext, pHead);
}

template <class T>
void displayList(Node<T> * pHead)
{
    std::cout << "{ ";
    while(pHead->pNext)
    {
        std::cout << pHead->data << ", ";
        pHead = pHead->pNext;
    }
    std::cout << pHead->data << " }\n";
}

template <class T>
Node<T> * findLinkedListIntersect(Node<T> * pHead1, Node<T> * pHead2, Node<T> * pHead1Prev = NULL, Node<T> * pHead2Prev = NULL)
{
    int length1 = listLength(pHead1);
    int length2 = listLength(pHead2);
    pHead1 = reverseList(pHead1);
    int length3 = listLength(pHead2);
    int pHead1Intersect = (length1 + length3 - length2) / 2;
    int pHead2Intersect = (length2 + length3 - length1) / 2;
    pHead1 = reverseList(pHead1);

    //parse to the intersect point
    Node<T> * intersect = pHead1;
    Node<T> * intersect2 = pHead2;
    for(int i = 0; i < pHead1Intersect; i++)
    {
        intersect = intersect->pNext;
    }

    for(int i = 0; i < pHead2Intersect; i++)
    {
        intersect2 = intersect2->pNext;
    }

    if(intersect != intersect2) //make sure that there actually was an intersection
    {
        return NULL;
    }
    else
    {
        return intersect;
    }
    
    std::cout << "THE INTERSECT POINT IS: " << intersect->data << std::endl;
}



int main()
{
    Node<int> * pHead1 = new Node<int>(1);
    Node<int> * pHead2 = new Node<int>(2);

    pHead1->pNext = new Node<int>(3); 
    pHead1->pNext->pNext = new Node<int>(5);
    pHead1->pNext->pNext->pNext = new Node<int>(7);
    pHead1->pNext->pNext->pNext->pNext = new Node<int>(9);
    std::cout << "Phead1: ";
    displayList(pHead1);

    pHead2->pNext = new Node<int>(4); 
    pHead2->pNext->pNext = new Node<int>(6);
    pHead2->pNext->pNext->pNext = new Node<int>(12); //pHead1->pNext;
    std::cout << "Phead2: ";
    displayList(pHead2);

    Node<int> * intersect = findLinkedListIntersect(pHead1, pHead2);
    if(intersect != NULL)
    {
        std::cout << "The intersect is the node with data: " << intersect->data << std::endl;
    }
}