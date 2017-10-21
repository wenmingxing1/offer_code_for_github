struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
            return NULL;

        list<TreeNode*> path1;
        list<TreeNode*> path2;

        GetNodePath(root, p, path1);    //待会判断真假
        GetNodePath(root, q, path2);

        return GetLastCommonNode(path1, path2);

    }
private:
    bool GetNodePath(TreeNode* root, TreeNode* pNode, list<TreeNode*> &path){   //得到节点路径
        path.push_back(root);
        if (root == pNode)
            return true;

        bool found = false;

        if (!found && root->left != NULL)
            found = GetNodePath(root->left, pNode, path);
        if (!found && root->right != NULL)
            found = GetNodePath(root->right, pNode, path);

        if (!found)
            path.pop_back();

        return found;
    }

    TreeNode* GetLastCommonNode(list<TreeNode*> path1, list<TreeNode*> path2){  //寻找两跳路径上的最后一个公共节点
        list<TreeNode*>::iterator iterator1 = path1.begin();
        list<TreeNode*>::iterator iterator2 = path2.begin();

        TreeNode* pLast = NULL;
        while (iterator1 != path1.end() && iterator2 != path2.end()){
            if (*iterator1 == *iterator2)
                pLast = *iterator1;
            iterator1++;
            iterator2++;
        }
        return pLast;
    }
};
