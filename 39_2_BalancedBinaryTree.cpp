struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/*===============方法一，需要多次遍历同一节点====================*/
class Solution
{
public:
    bool IsBalancedTree(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return true;
        int Left = TreeDepth(pRoot->left);
        int Right = TreeDepth(pRoot->right);
        int diff = Left - Right;
        if (diff > 1 || diff < -1)
            return false;

        return IsBalancedTree(pRoot->left) && IsBalancedTree(pRoot->right);
    }
private:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int Left = TreeDepth(pRoot->left);
        int Right = TreeDepth(pRoot->right);

        return (Left >= Right) ? (Left + 1) : (Right + 1);
    }
};

/*====================方法二，每个节点只需要遍历一次======================*/
class Solution2
{
public:
    bool IsBalancedTree(TreeNode* pRoot)
    {

    }
};
