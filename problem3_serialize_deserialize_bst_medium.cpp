/***
 * This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*
*/

#define DEBUG
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

template <class T>
class Node
{
    public:

        Node(T data, Node * left = NULL, Node * right = NULL)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }

        ~Node()
        {
            if(left)
                delete left;
            if(right)
                delete right;  
        }

    private:
        T data;
        Node * left;
        Node * right;
        

    friend string serialize(Node<string> * root);
    friend string serialize(Node<int> * root);
    friend string serialize(Node<T> * root);
    #ifdef DEBUG
    friend int main();
    #endif
};

string serialize(Node<string> * root)
{
    if(root == NULL)
        return "NULL";

    if(root->right && root->left)
        return "Node(\"" + root->data + "\", " + serialize(root->left)
            + ", " + serialize(root->right) + ")";
    if(root->left)
        return "Node(\"" + root->data + "\", " + serialize(root->left) + ")";
    
    if(root->right)
        return "Node(\"" + root->data + "\", NULL, " + serialize(root->right) + ")";
    
    
    return "Node(\"" + root->data + "\")";
    
}


string serialize(Node<int> * root)
{
    
    if(root == NULL)
        return "NULL";

    if(root->right && root->left)
        return "Node(" + to_string(root->data) + ", " + serialize(root->left)
            + ", " + serialize(root->right) + ")";
    if(root->left)
        return "Node(" + to_string(root->data) + ", " + serialize(root->left) + ")";
    
    if(root->right)
        return "Node(" + to_string(root->data) + ", NULL, " + serialize(root->right) + ")";
    
    return "Node(" + to_string(root->data) + ")";
    
    
}

Node <string> * deserializeS(string s)
{
     
    if(s == "NULL")
        return NULL;
    string dataString = "";
    //find the beginning of the data.
    int i = s.find('"');
    
    if(i == string::npos)
        throw "Cannot deserialize for a Node<string> * when given a different data type.";
    else
        i++;
    
    //with strings, we are looking for data between the quotes
    uint numQuotes = 1;
    //find the starting quote
    //create the data string
    while(true)
    {
        //if we find the closing quote, we are done with the data.
        if(s[i] == '"' && s[i - 1] != '\\')
            break;
        dataString += s[i];
        i++;
    }
   

    uint numParens = 1;
    string leftSerialize = "";
    //Move to the next capital 'N'
    i = s.find('N', i + 1);
    //"Node"
    while(i < s.size() && s[i] != '(' && leftSerialize != "NULL")
        leftSerialize += s[i++];
    //"Node("
    if(i < s.size() && leftSerialize != "NULL")
        leftSerialize += s[i++];
    
    //"Node(data, left, right)"
    while(i < s.size() && numParens > 0 && leftSerialize != "NULL")
    {
        if(s[i] == '(')
            numParens++;
        else if(s[i] == ')')
            numParens--;
        leftSerialize += s[i];
        i++;
        
    }

    string rightSerialize = "";
    numParens = 1;
    if(i != string::npos)
        i = s.find('N', i + 1);
    
    while(i < s.size() && s[i] != '(' && rightSerialize != "NULL")
        rightSerialize += s[i++];
    if(i < s.size() && rightSerialize != "NULL")
        rightSerialize += s[i++];
    while(i < s.size() && numParens > 0 && rightSerialize != "NULL")
    {
        if(s[i] == '(')
            numParens++;
        else if(s[i] == ')')
            numParens--;
        rightSerialize += s[i];
        i++;
        
    }
    Node<string> * left = NULL;
    Node<string> * right = NULL;
    if(leftSerialize.size() > 0)
        left = deserializeS(leftSerialize);
    if(rightSerialize.size() > 0)
        right = deserializeS(rightSerialize);

    //cout << leftSerialize;
    Node<string> * node = new Node<string>(dataString, left, right);


    return node;
}

Node <int> * deserializeI(string s)
{
    if(s == "NULL")
        return NULL;
    string dataString = "";
    int data;
    stringstream ss;
    //find the beginning of the data.
    int i = s.find('"') + 1;
    //with strings, we are looking for data between the quotes
    uint numQuotes = 1;
    //find the starting quote
    //create the data string
    while(!isdigit(s[i])) i++;
    while(true)
    {
        //if we find the closing quote, we are done with the data.
        if(!isdigit(s[i]))
            break;
        dataString += s[i];
        i++;
    }
    ss << dataString;
  
    ss >> data;

    ss.clear();

    uint numParens = 1;
    string leftSerialize = "";
    //Move to the next capital 'N'
    i = s.find('N', i + 1);

    //"Node"
    while(i < s.size() && s[i] != '(' && leftSerialize != "NULL")
        leftSerialize += s[i++];
    //"Node("
    if(i < s.size() && leftSerialize != "NULL")
        leftSerialize += s[i++];
    
    //"Node(data, left, right)"
    while(i < s.size() && numParens > 0 && leftSerialize != "NULL")
    {
        if(s[i] == '(')
            numParens++;
        else if(s[i] == ')')
            numParens--;
        leftSerialize += s[i];
        i++;
        
    }

    string rightSerialize = "";
    numParens = 1;
    if(i != string::npos)
        i = s.find('N', i + 1);
    
    while(i < s.size() && s[i] != '(' && rightSerialize != "NULL")
        rightSerialize += s[i++];
    if(i < s.size() && rightSerialize != "NULL")
        rightSerialize += s[i++];
    while(i < s.size() && numParens > 0 && rightSerialize != "NULL")
    {
        if(s[i] == '(')
            numParens++;
        else if(s[i] == ')')
            numParens--;
        rightSerialize += s[i];
        i++;
        
    }
    Node<int> * left = NULL;
    Node<int> * right = NULL;
    if(leftSerialize.size() > 0)
        left = deserializeI(leftSerialize);
    if(rightSerialize.size() > 0)
        right = deserializeI(rightSerialize);

    //cout << leftSerialize;
    Node<int> * node = new Node<int>(data, left, right);


    return node;
}



int main()
{
    try
    {
    Node<int> * node = new Node<int>(1, 
                                new Node<int>(2, new Node<int>(4, new Node<int>(6)), 
                                new Node<int>(3, NULL, new Node<int>(5))));
    string s = serialize(node);
    Node<int> * node2 = deserializeI(s);
    cout << serialize(node2) << endl;
    
    Node<string> * strNode = new Node<string>("root", 
                            new Node<string>("left", new Node<string>("left.left", new Node<string>("left.right")), 
                            new Node<string>("right", NULL, new Node<string>("right.right"))));
    
    s = serialize(strNode); 
   
    Node<string> * strNode2 = deserializeS(s);
    cout << serialize(strNode2) << endl;

    //PASSED this assert
    Node<string> * nodeTest = new Node<string>("root", new Node<string>("left", new Node<string>("left.left")), new Node<string>("right"));
    assert(deserializeS(serialize(nodeTest))->left->left->data == "left.left");

    delete node;
    delete node2;
    delete strNode;
    delete strNode2;
    }
    catch(const char * error)
    {
        cout << error << endl;
    }
}
