/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
private:
    //���ƽڵ�
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while (pNode != NULL){
            RandomListNode* pCloned = new RandomListNode(pNode->label);		//ÿ�α����½��ڵ�
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;

            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }

    //����randomָ��
    void ConnectRandomNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while (pNode != NULL){
            RandomListNode* pCloned = pNode->next;
            if (pNode->random != NULL)
            	pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
    }

    //�������
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;

        if (pNode != NULL){		//����ͷ���
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while (pNode != NULL){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
};
