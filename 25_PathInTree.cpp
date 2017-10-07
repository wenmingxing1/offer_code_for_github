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
    vector<vector<int>> res;    //��res��path����Ϊȫ�ֱ���
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
        if ((root->val == sum) && isLeaf){      //�ж��Ƿ���������
            res.push_back(path);
        }
        else{       //��������㣬��ݹ�
            if (root->left != NULL)
                find(root->left, sum - root->val);
            if (root->right != NULL)
                find(root->right, sum - root->val);
        }
        path.pop_back();    //�ڷ��ص������֮ǰ����·����ɾ����ǰ�ڵ�
    }
};
