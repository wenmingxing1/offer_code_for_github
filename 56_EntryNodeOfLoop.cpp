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
        //��ʱlengthΪ���ĳ���

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
    //ͨ������ָ���ж��Ƿ��л������ҷ��ػ��е�һ���ڵ�Ϊ�󻷵ĳ�����׼��
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
                pFirst = pFirst->next;		//��ָ��ÿ��������
        }
        return NULL;	//���������while��������֤��û�л�������NULL
    }
};
