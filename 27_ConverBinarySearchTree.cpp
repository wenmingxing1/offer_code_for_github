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
        ConverNode(pRootOfTree, &pLastNodeInList);  //��Ϊ�����β��Ƕ���ָ�룬������Ҫ��ȡ��ַ��

        TreeNode* pHeadOfList = pLastNodeInList;
        while (pHeadOfList != NULL && pHeadOfList->left != NULL)
            pHeadOfList = pHeadOfList->left;
        return pHeadOfList;
    }
private:
    //�������������
    void ConverNode(TreeNode* pNode, TreeNode** pLastNodeInList){   //��Ϊ��Ҫ��pLastNodeInList���ж�̬�ı䣬������Ҫ�ö���ָ��
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
