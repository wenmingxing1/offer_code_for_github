/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == NULL)
            return res;
        std::queue<TreeNode*> nodes;
        nodes.push(pRoot);
        while (!nodes.empty()){
            vector<int> temp;
            int size = nodes.size();
            for (int i = 0; i < size; ++i){
                TreeNode* pNode = nodes.front();
                temp.push_back(pNode->val);
                nodes.pop();

                if (pNode->left != NULL) nodes.push(pNode->left);
                if (pNode->right != NULL) nodes.push(pNode->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
