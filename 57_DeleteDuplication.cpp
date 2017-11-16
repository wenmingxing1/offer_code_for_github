/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        ListNode* pPre = NULL;
        ListNode* pNode = pHead;

        while (pNode != NULL){
            ListNode* pNext = pNode->next;
            bool del = false;
            if (pNext != NULL && pNext->val == pNode->val)
                del = true;

            if (!del){	//����Ҫɾ��
                pPre = pNode;
                pNode = pNode->next;
            }
            else{ 	//��Ҫɾ��
                int value = pNode->val;
                ListNode* pToBeDel = pNode;
                while (pToBeDel != NULL && pToBeDel->val == value){
                    pNext = pToBeDel->next;
                    delete pToBeDel;
                    pToBeDel = NULL;

                    pToBeDel = pNext;
                }

                if(pPre == NULL)
                    pHead = pNext;
                else
                    pPre->next = pNext;

                pNode = pNext;
            }
        }
        return pHead;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* first = new ListNode(-1);	//����һ����ʼλ�ã�����ʼ��Ϊ����
        first->next = pHead;
        ListNode* pNode = pHead;
        ListNode* pre = first;

        while (pNode != NULL && pNode->next != NULL){
            if (pNode->val == pNode->next->val){
                //�����ظ�Ԫ��
                int val = pNode->val;
                while (pNode != NULL && val == pNode->val){
                    pNode = pNode->next;
                }
                pre->next = pNode;
            }
            else{
                pre = pNode;
                pNode = pNode->next;
            }
        }
        return first->next;
    }
};
