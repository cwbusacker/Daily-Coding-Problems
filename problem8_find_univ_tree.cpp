/*
This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where 
all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/
#include <string>
#include <iostream>

template<class T>
struct bNode
{
    bNode(T data) : left(NULL), 
            right(NULL), parent(NULL) 
            { this->data = data; }
    T data;
    bNode * left;
    bNode * right;
    bNode * parent;
};

template <class T>
void cleanUp(bNode<T> * root)
{
    if(root->left)
        cleanUp(root->left);
        
    if(root->right)
        cleanUp(root->right);

    delete root;
        
}
template<class T>
bool isUnivTree(bNode<T> *root)
{
    if(root->right == NULL && root->left == NULL)
    {
        return true;
    }

    if(root->right != NULL && root->left != NULL)
    {
        return root->right->data == root->data  && root->left->data == root->data
                 && isUnivTree(root->right) && isUnivTree(root->left);
                
               
    }

    if(root->right != NULL)
    {
        return root->right->data == root->data && isUnivTree(root->right);
    }

    if(root->left != NULL)
    {
        return root->left->data == root->data && isUnivTree(root->left);
    }

    return false;
}


template <class T>
unsigned int countUnivTrees(bNode<T> * root)
{
    if(root->right == NULL && root->left == NULL)
    {
        return 1;
    }

    if(root->left && root->right)
    {
       if(isUnivTree(root))
       {
           return 1 + countUnivTrees(root->left) + countUnivTrees(root->right);
       }
       else
       {
            return countUnivTrees(root->left) + countUnivTrees(root->right);
       }
       
    }

    if(root->left)
    {
        if(isUnivTree(root))
        {
            return 1 + countUnivTrees(root->left);
        }
        else
        {
            return countUnivTrees(root->left);
        }
    }

    if(root->right)
    {
        if(isUnivTree(root))
        {
            return 1 + countUnivTrees(root->right);
        }
        else
        {
            return countUnivTrees(root->right);
        }
    }
  
  return 0;
    
}

int main()
{
    bNode<int> * root = new bNode<int>(0);
    root->left = new bNode<int>(1);
    root->right = new bNode<int>(0);
    root->right->left = new bNode<int>(1);
    root->right->left->left = new bNode<int>(1);
    root->right->left->right = new bNode<int>(1);
    root->right->right = new bNode<int>(0);

    int count = countUnivTrees(root);
    std::cout << "There are " << count << " universal subtrees in this tree.\n";
}
