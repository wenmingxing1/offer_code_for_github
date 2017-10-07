//�������Ĳ������
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

        std::deque<TreeNode*> dequeTreeNode;    //���ö��������ȳ�������
        dequeTreeNode.push_back(root);
        while (dequeTreeNode.size()){   //��������д���Ԫ�أ��ڵ�����Ԫ�ص�ͬʱѹ�����Ԫ�ض�Ӧ����������
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
