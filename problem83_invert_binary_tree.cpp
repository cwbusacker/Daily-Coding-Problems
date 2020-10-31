#include <iostream>

template <class T>
struct bNode
{
    bNode(T data)
    {
        this->data = data;
        pLeft = NULL;
        pRight = NULL;
    }

    T data;
    bNode * pLeft;
    bNode * pRight;
};

template <class T>
void invertTree(bNode<T> * pRoot)
{
    if(pRoot == NULL)
        return;

    bNode<T> * copy = pRoot->pRight;
    pRoot->pRight = pRoot->pLeft;
    pRoot->pLeft = copy;
    
    invertTree(pRoot->pRight);
    invertTree(pRoot->pLeft);
}

template <class T>
void displayTree(std::string data, bNode<T> * node)
{
    if(node == NULL)
    {
        return;
    }

    std::cout << data << ": " << node->data  << "\n";
    displayTree(data + "->pLeft", node->pLeft);
    displayTree(data + "->pRight", node->pRight);
}
int main()
{
    bNode<char> * root = new bNode<char>('a');
    root->pLeft = new bNode<char>('b');
    root->pRight = new bNode<char>('c');
    root->pLeft->pLeft = new bNode<char>('d');
    root->pLeft->pRight = new bNode<char>('e');
    root->pRight->pLeft = new bNode<char>('f');

    invertTree(root);
}