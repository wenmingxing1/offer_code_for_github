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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNodeInList = NULL;
        ConverNode(pRootOfTree, &pLastNodeInList);  //因为函数形参是二重指针，所以需要用取地址符

        TreeNode* pHeadOfList = pLastNodeInList;
        while (pHeadOfList != NULL && pHeadOfList->left != NULL)
            pHeadOfList = pHeadOfList->left;
        return pHeadOfList;
    }
private:
    //类似于中序遍历
    void ConverNode(TreeNode* pNode, TreeNode** pLastNodeInList){   //因为需要对pLastNodeInList进行动态改变，所以需要用二重指针
        if (pNode == NULL)
            return;

        TreeNode* pCurrent = pNode;
        if (pCurrent->left != NULL)
            ConverNode(pCurrent->left, pLastNodeInList);

        pCurrent->left = *pLastNodeInList;

        if (*pLastNodeInList != NULL)
            (*pLastNodeInList)->right = pCurrent;

        *pLastNodeInList = pCurrent;

        if (pCurrent->right != NULL)
            ConverNode(pCurrent->right, pLastNodeInList);
    }
};
