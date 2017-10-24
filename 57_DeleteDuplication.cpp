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

            if (!del){	//不需要删除
                pPre = pNode;
                pNode = pNode->next;
            }
            else{ 	//需要删除
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
