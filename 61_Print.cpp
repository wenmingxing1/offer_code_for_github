struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> Print(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return res;
        std::queue<TreeNode*> nodes;
        nodes.push(pRoot);
        bool even = false;  //判断奇偶层，看是否需要reverse
        while (!nodes.empty())
        {
            vector<int> temp;
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* pNode = nodes.front();
                temp.push_back(pNode->val);
                nodes.pop();

                if (pNode->left != NULL) nodes.push(pNode->left);
                if (pNode->right != NULL) nodes.push(pNode->right);
            }
            if (even)
                std::reverse(temp.begin(), temp.end());
            even = !even;
            res.push_back(temp);
        }
        return res;
    }
};
