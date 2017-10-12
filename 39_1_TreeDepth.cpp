#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;

        int Left = TreeDepth(pRoot->left);
        int Right = TreeDepth(pRoot->right);

        return (Left >= Right) ? Left : Right;
    }
};

