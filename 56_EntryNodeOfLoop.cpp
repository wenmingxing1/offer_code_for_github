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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        ListNode* meetingNode = MeetingNode(pHead);
        if (meetingNode == NULL)
            return NULL;

        int length = 1;
        ListNode* pNode = meetingNode->next;
        while (pNode != meetingNode){
            pNode = pNode->next;
            length++;
        }
        //此时length为环的长度

        ListNode* pNode1 = pHead;
        ListNode* pNode2 = pHead;
        for (int i = 0; i < length; ++i){
            pNode2 = pNode2->next;
        }

        while (pNode1 != pNode2){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
private:
    //通过快慢指针判断是否有环，并且返回环中的一个节点为求环的长度做准备
    ListNode* MeetingNode(ListNode* pHead){
        if (pHead == NULL)
            return NULL;
        ListNode* pSlow = pHead->next;
        if (pSlow == NULL)
            return NULL;
        ListNode* pFirst = pSlow->next;

        while (pSlow != NULL && pFirst != NULL){
            if (pSlow == pFirst)
                return pSlow;
            pSlow = pSlow->next;
            pFirst = pFirst->next;

            if (pFirst != NULL)
                pFirst = pFirst->next;		//快指针每次走两步
        }
        return NULL;	//如果不满足while条件，则证明没有环，返回NULL
    }
};
