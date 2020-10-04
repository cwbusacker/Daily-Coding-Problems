/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/
#include <iostream>

struct bNode
{
    std::string data;
    bNode * left;
    bNode * right;
    bNode * parent;
};

void cleanUp(bNode * root)
{
    if(root->left)
        cleanUp(root->left);
        
    if(root->right)
        cleanUp(root->right);

    delete root;
        
}

bNode * buildTreeLeft(std::string msg);
bNode * buildTreeRight(std::string msg);

int countLeaves(bNode * root, bool display = false)
{
    int count = 0;
    if(root->left == NULL && root->right == NULL)
    {

        if(display)
        {
            std::string str = "";
            bNode * leaf = root;
            while(leaf->data != "ROOT")
            {   
                str += (char)(stoi(leaf->data) + 64);
                leaf = leaf->parent;
            }

            for(std::string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
                std::cout << *it;
            std::cout << std::endl;
        }

        return 1;
    }
        
    
    if(root->left)
    {
        count += countLeaves(root->left, display);
    }
    
    if(root->right)
    {
        count += countLeaves(root->right, display);
    }


    return count;
}

//only handles numbers between 10 and 26
bNode * buildTreeRight(std::string msg)
{
    bNode * right = NULL;
    if(msg.length() >= 2
    && ((msg[0] == '1') 
    || (msg[0] == '2' && msg[1] >= '0' && msg[1] <= '6')))
    {
        right = new bNode;
        right->data = std::string() + msg[0] + msg[1];
        right->left = buildTreeLeft(msg.substr(2));
        right->right = buildTreeRight(msg.substr(2));
        if(right->right)
            right->right->parent = right;
        if(right->left)
            right->left->parent = right;
    }
    return right;
}

//handles single digits only
bNode * buildTreeLeft(std::string msg)
{
    bNode * left = NULL;
    if(msg.length() > 0 && msg[0] != '0')
    {
        left = new bNode;
        left->data = msg[0];
        left->left = buildTreeLeft(msg.substr(1));
        left->right = buildTreeRight(msg.substr(1));
        if(left->left)
            left->left->parent = left;
        if(left->right)
            left->right->parent = left;
    }
    return left;
}

unsigned int parseEncodedMessage(std::string encoded, bool showPossibleMsgs = false)
{
   /*
            1112:
                    ROOT
            /-------|-------\
            1               11
        /-------\        /-------\
       1       11       1       12
      / \       /      / \     
     1   12    2      2   N
    /          
   2         

    COUNT THE NON_NULL LEAVES
   */

  bNode * root = new bNode;
  root->data = "ROOT";
  root->left = buildTreeLeft(encoded);
  root->right = buildTreeRight(encoded);
  if(root->left)
    root->left->parent = root;
  if(root->right)
    root->right->parent = root;

  unsigned int retVal = countLeaves(root, showPossibleMsgs);

  cleanUp(root);
  return retVal;
}

int main()
{
    std::string encoded;
    std::cout << "What is the encoded message? ";
    std::cin >> encoded;
    std::cout << "POSSIBLE COMBINATIONS INCLUDE:\n";
    int total = parseEncodedMessage(encoded, true);
    std::cout << "There are " << total << " possible ways to decode this message\n";

}