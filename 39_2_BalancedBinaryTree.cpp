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

        return (Left >= Right) ? (Left + 1) : (Right + 1);  //更新深度
    }
};

/*====================方法二，每个节点只需要遍历一次======================*/
class Solution2
{
public:
    bool IsBalancedTree(TreeNode* pRoot)
    {
        int Depth = 0;
        return IsBalanced(pRoot, Depth);
    }
private:
    bool IsBalanced(TreeNode* pRoot, int& depth)    //必须将depth设置为引用，因为在遍历过程中depth需要改变
    {
        if (pRoot == NULL)  //递归结束条件
        {
            depth = 0;
            return true;
        }
        int left = right = 0;
        if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right))
        {
            int diff = left - right;
            if (diff <= 1 && diff >= -1)
            {
                depth = 1 + (left>right?left:right);    //更新depth
                return true;
            }
        }
        return false;
    }
};
