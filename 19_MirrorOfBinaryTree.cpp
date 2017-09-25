#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x): val(x), left(NULL), right(NULL) {}

    static void PreOrder(BinaryTreeNode* root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    static void InOrder(BinaryTreeNode* root)
    {
        if (root == NULL)
            return;
        InOrder(root->left);
        cout << root->val << " ";
        InOrder(root->right);
    }

    static void LatOrder(BinaryTreeNode* root)
    {
        if (root == NULL)
            return;
        LatOrder(root->left);
        cout << root->val << " ";
        LatOrder(root->right);
    }
};

class Solution
{
public:
    void mirrorOfBinaryTree(BinaryTreeNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        if (pNode->left == NULL && pNode->right == NULL)    //µÝ¹é½áÊøÌõ¼þ
            return NULL;

        BinaryTreeNode* temp;
        temp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = temp;

        if (pNode->left)
            mirrorOfBinaryTree(pNode->left);
        if (pNode->right)
            mirrorOfBinaryTree(pNode->right);
    }
};

