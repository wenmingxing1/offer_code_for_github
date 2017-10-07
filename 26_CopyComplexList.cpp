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
    //复制节点
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while (pNode != NULL){
            RandomListNode* pCloned = new RandomListNode(pNode->label);		//每次必须新建节点
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;

            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }

    //设置random指针
    void ConnectRandomNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while (pNode != NULL){
            RandomListNode* pCloned = pNode->next;
            if (pNode->random != NULL)
            	pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
    }

    //拆分链表
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;

        if (pNode != NULL){		//处理头结点
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
