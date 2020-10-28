#include <vector>
#include <iostream>
using std::vector;

template <class T>
struct bNode
{
    bNode(T data) 
    {
        this->data = data;
    }

    ~bNode()
    {
        if(pLeft)
        {
            delete pLeft;
        }

        if(pRight)
        {
            delete pRight;
        }
    }
    T data;
    bNode<T> * pLeft;
    bNode<T> * pRight;
};

template <class T>
vector <vector <T> > findPathToEachLeaf(bNode<T> * node, vector<T> & pathNow)
{
    vector <vector <T> > retVal;
    pathNow.push_back(node->data);
    if(node->pLeft == nullptr && node->pRight == nullptr)
    {
        retVal.push_back(pathNow);
        pathNow.pop_back();
        return retVal;
    }

    vector<vector <T> > resultLeft, resultRight;
    if(node->pLeft)
    {
        resultLeft = findPathToEachLeaf(node->pLeft, pathNow);
    }

    if(node->pRight)
    {
        resultRight = findPathToEachLeaf(node->pRight, pathNow);
    }

    retVal.reserve(resultLeft.size() + resultRight.size());
    retVal.insert(retVal.end(), resultLeft.begin(), resultLeft.end());
    retVal.insert(retVal.end(), resultRight.begin(), resultRight.end());

    return retVal;

}


int main()
{
    /*       a
       c           b
                d     e
                     g  f

    */
    bNode<char> * root = new bNode<char>('a');
    root->pRight = new bNode<char>('b');
    root->pLeft = new bNode<char>('c');
    root->pRight->pLeft = new bNode<char> ('d');
    root->pRight->pRight = new bNode<char> ('e');
    root->pRight->pRight->pRight = new bNode<char>('f');
    root->pRight->pRight->pLeft = new bNode<char>('g');

    vector <char> path;
    vector< vector <char> > leafPaths = findPathToEachLeaf(root, path);

    std::cout << "The paths to the binary tree leaves include:\n";
    for(unsigned int i = 0; i < leafPaths.size(); i++)
    {
        for(unsigned int j = 0; j < leafPaths[i].size(); j++)
        {
            if(j == 0)
            {
                std::cout << "{ ";
            }
            else
            {
                std::cout << ", ";
            }

            std::cout << leafPaths[i][j];
            
        }

        std::cout << "}\n";
    }
    delete root;

}