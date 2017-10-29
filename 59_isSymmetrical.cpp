struct TreeNode
{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
};

class Solution
{
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }
private:
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL && pRoot2 == NULL)   //两个同时为NULL
            return true;
        if (pRoot1 == NULL || pRoot2 == NULL)   //如果只有一个先到达NULL
            return false;
        if (pRoot1->val != pRoot2->val)     //一旦不相等
            return false;

        return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
    }

};
