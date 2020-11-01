#include <string>
#include <iostream>
using std::string;

struct BNode
{
    BNode(string data)
    {
        this->data = data;
        left = right = nullptr;
    }
    string data;
    BNode * left;
    BNode * right;
};

int computeMathBTree(BNode * root)
{
    if(root == nullptr)
        return 0;

    if(isdigit(root->data[0]))
    {
        return std::stoi(root->data);
    }

    int l = computeMathBTree(root->left); 
    int r = computeMathBTree(root->right);

    char op = root->data[0];

    switch(op)
    {
        case '*':
            return l * r;
        case '-':
            return l - r;
        case '+':
            return l + r;
        case '/':
            return l / r;
        case '%':
            return l % r;
        case '&':
            return l & r;
        case '|':
            return l | r;
    }

    return 0;
}

int main()
{
    BNode * root = new BNode("*");

    root->left = new BNode("+");
    root->left->left = new BNode("3");
    root->left->right = new BNode("2");

    root->right = new BNode("+");
    root->right->left = new BNode("4");
    root->right->right = new BNode("5");

    // (3 + 2) * (4 + 5) = 45
    

    std::cout << "The evaluation tree result is " << computeMathBTree(root) << std::endl;
}