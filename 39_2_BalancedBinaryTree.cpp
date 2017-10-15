struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/*===============����һ����Ҫ��α���ͬһ�ڵ�====================*/
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

        return (Left >= Right) ? (Left + 1) : (Right + 1);  //�������
    }
};

/*====================��������ÿ���ڵ�ֻ��Ҫ����һ��======================*/
class Solution2
{
public:
    bool IsBalancedTree(TreeNode* pRoot)
    {
        int Depth = 0;
        return IsBalanced(pRoot, Depth);
    }
private:
    bool IsBalanced(TreeNode* pRoot, int& depth)    //���뽫depth����Ϊ���ã���Ϊ�ڱ���������depth��Ҫ�ı�
    {
        if (pRoot == NULL)  //�ݹ��������
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
                depth = 1 + (left>right?left:right);    //����depth
                return true;
            }
        }
        return false;
    }
};
