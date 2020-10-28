#include <iostream>

template <class T>
struct bNode
{
    bNode(T data, bNode<T> * pParent = nullptr)
    {
        pLeft = pRight = NULL;
        this->data = data;
        this->pParent = pParent;
    }
    
    bool getIsLocked()
    {
        return locked;
    }

    bool lock()
    {
        if(is_children_locked(this) || is_ancestors_locked(this))
        {
            return false;
        }

        locked = true;
        return true;
    }

    bool unlock()
    {
       if(is_children_locked(this) || is_ancestors_locked(this))
        {
            return false;
        }

        locked = false;
        return true;
    }

    bool is_ancestors_locked(bNode<T> * node, bool includeSelf = false)
    {
        if(node == nullptr)
        {
            return false;
        }

        if(includeSelf && node->getIsLocked())
        {
            return true;
        }

        return is_ancestors_locked(node->pParent, true);
    }

    bool is_children_locked(bNode<T> * node, bool includeSelf = false)
    {
        if(node == nullptr)
        {
            return false;
        }

        if(includeSelf && node->getIsLocked())
        {
            return true;
        }

        return is_children_locked(node->pLeft, true) && is_children_locked(node->pRight, true);
    }

    bool locked;
    bNode * pLeft;
    bNode * pRight;
    bNode * pParent;
    T data;
};

int main()
{
    //build a tree
    bNode<char> * charTree = new bNode<char>('a');
    charTree->pLeft = new bNode<char>('b', charTree);
    charTree->pRight = new bNode<char>('c', charTree);
    charTree->pLeft->pLeft = new bNode<char>('d', charTree->pLeft);
    charTree->pLeft->pRight = new bNode<char>('e', charTree->pLeft);

    if(charTree->lock())
    {
        std::cout << "Root locked!\n";
    }
    
    if(charTree->pLeft->pLeft->lock() == false)
    {
        std::cout << "Not able to lock root->left->left.\n";
    }
    else
    {
        std::cout << "LOCKED ROOT->LEFT->LEFT!!!\n";
    }

    if(charTree->unlock())
    {
        std::cout << "Root unlocked\n";
    }
    else
    {
        std::cout << "UNABLE TO UNLOCK ROOT!!!\n";
    }

    if(charTree->pLeft->pLeft->lock() == false)
    {
        std::cout << "NOT ABLE TO LOCK ROOT->LEFT->LEFT!!!\n";
    }
    else
    {
        std::cout << "Locked Root->left->left\n";
    }
    

}