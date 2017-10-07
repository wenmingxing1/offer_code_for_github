/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int>> res;    //将res和path设置为全局变量
    vector<int> path;
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }
private:
    void find(TreeNode* root, int sum){
        if (root == NULL)
            return;
        path.push_back(root->val);
        bool isLeaf = root->left == NULL && root->right == NULL;
        if ((root->val == sum) && isLeaf){      //判断是否满足条件
            res.push_back(path);
        }
        else{       //如果不满足，则递归
            if (root->left != NULL)
                find(root->left, sum - root->val);
            if (root->right != NULL)
                find(root->right, sum - root->val);
        }
        path.pop_back();    //在返回到父结点之前，在路径上删除当前节点
    }
};
