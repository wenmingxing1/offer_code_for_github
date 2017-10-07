//二叉树的层序遍历
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;

        if (root == NULL)
            return result;

        std::deque<TreeNode*> dequeTreeNode;    //利用队列先入先出的特性
        dequeTreeNode.push_back(root);
        while (dequeTreeNode.size()){   //如果队列中存在元素，在弹出首元素的同时压入这个元素对应的左右子树
            TreeNode* pNode = dequeTreeNode.front();
            result.push_back(pNode->val);
            dequeTreeNode.pop_front();

            if (pNode->left != NULL)
                dequeTreeNode.push_back(pNode->left);
            if (pNode->right != NULL)
                dequeTreeNode.push_back(pNode->right);
        }
        return result;

    }
};
