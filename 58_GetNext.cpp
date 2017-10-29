/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        TreeLinkNode* pRes = NULL;
        if (pNode->right != NULL){
            TreeLinkNode* pRight = pNode->right;
            while (pRight->left != NULL)
                pRight = pRight->left;
            pRes = pRight;
        }
        else{
            while (pNode->next != NULL){	//ֱ���ҵ��˽�����丸�������ӣ����������������ֱ�ӷ��أ����������������
                if (pNode->next->left == pNode)
                    return pNode->next;
                pNode = pNode->next;
            }
            pRes = pNode->next;
        }
        return pRes;
    }
};
