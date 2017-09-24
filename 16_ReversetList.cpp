//三指针滑动法
#include<iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* ReversetList(ListNode* pHead)
{
    ListNode* pPrev = NULL;
    ListNode* pNode = pHead;
    ListNode* pNewHead = NULL;

    while (pNode != NULL)
    {
        ListNode *pNext = pNode->m_pNext;

        if (pNext == NULL)  //到达最后一个赋给新链表头部
            pNewHead = pNode;

        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pNewHead;
}

int main()
{
    ListNode List[5];

    List[0].m_nValue = 1;
    List[0].m_pNext = &List[1];
    List[1].m_nValue = 2;
    List[1].m_pNext = &List[2];
    List[2].m_nValue = 3;
    List[2].m_pNext = &List[3];
    List[3].m_nValue = 4;
    List[3].m_pNext = &List[4];
    List[4].m_nValue = 5;
    List[4].m_pNext = NULL;

    ListNode* node = List;

    while (node != NULL)
    {
        cout << node->m_nValue << " ";
        node = node->m_pNext;
    }

    cout << endl;

    node = ReversetList(List);  //链表必须以头结点开始才能遍历，所以要返回一个node

    while (node != NULL)
    {
        cout << node->m_nValue << " ";
        node = node->m_pNext;
    }

}
