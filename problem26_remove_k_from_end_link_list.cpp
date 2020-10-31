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
bool removeNFromTheEnd(const int & removeMe, Node<T> *& root)
{
    if(root->pNext == nullptr && removeMe == 1)
    {
        delete root;
        root = nullptr;
        return true;
    }
    else
    {
        int x = removeNFromTheEndAssist(removeMe, root);
        std::cout << "X = " << x << " REMOVE ME = " << removeMe << std::endl;
        if(x == -2)
        {
            return true;
        }
        else if(x == -1)
        {
            Node<T> * newNext = root->pNext->pNext;
            delete root->pNext;
            root->pNext = newNext;
            return true;
        }
        else if(x == removeMe)
        {
            Node<T> * oldRoot = root;
            root = root->pNext;
            delete oldRoot;
            oldRoot = nullptr;
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
}

template <class T>
int removeNFromTheEndAssist(const int & removeMe, Node<T> * node)
{
    if(node->pNext == nullptr)
    {
        if(removeMe == 1)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    int x = removeNFromTheEndAssist(removeMe, node->pNext);
    if(x == -1) //-1 signifies that pNext needs removed.
    {
         Node<T> * newNext = node->pNext->pNext;
        delete node->pNext;
        node->pNext = newNext;
        return -2; //-2 signifies done!
    }
    else if(x == -2)
    {
        return -2; //-2 signifies done!
    }
    else if(x == removeMe) 
    {
        return -1; //send the message back to the previous function to remove
    }
    else if(x < removeMe)
    {
        return x + 1; // add one more node (moving backward)
    }
    else
    {
        return removeMe + 1; //return invalid
    }
    
}

template <class T>
void displayList(Node<T> * root)
{
    std::cout << "{ ";
    std::cout << root->data;
    root = root->pNext;
    while(root)
    {
        std::cout << ", " << root->data;
        root = root->pNext;
    }

    std::cout << " }\n";
}


int main()
{
    Node<char> * root = new Node<char> ('a');
    root->pNext = new Node<char> ('b');
    root->pNext->pNext = new Node<char> ('c');
    root->pNext->pNext->pNext = new Node<char> ('d');
    root->pNext->pNext->pNext->pNext = new Node<char>('e');
    root->pNext->pNext->pNext->pNext->pNext = new Node<char>('f');
    root->pNext->pNext->pNext->pNext->pNext->pNext = new Node<char>('g');
    root->pNext->pNext->pNext->pNext->pNext->pNext->pNext = new Node<char>('h');
    root->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = new Node<char>('i');
    root->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = new Node<char>('j');
    root->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = new Node<char>('k');
    root->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = new Node<char>('l');
    
    std::cout << "BEFORE: ";
    displayList(root);

    removeNFromTheEnd(1, root);

    std::cout << "END: ";
    displayList(root);
    
}