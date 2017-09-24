//遍历链表将每个节点在头部插入
#include<iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

class Solution
{
public:
    ListNode* ReversetList(ListNode* pHead)
    {
        ListNode* pNode = pHead;
        ListNode* pNew = NULL;
        ListNode* pNext = NULL;

        pNew = pNode;
        pNode = pNode->m_pNext;
        pNew->m_pNext = NULL;

        while (pNode != NULL)
        {
            ListNode* pNext = pNode->m_pNext;

            pNode->m_pNext = pNew;
            pNew = pNode;

            pNode = pNext;
        }
        return pNew;
    }
};

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

    Solution solu;
    ListNode* pnode = List;
    while (pnode != NULL)
    {
        cout << pnode->m_nValue << " ";
        pnode = pnode->m_pNext;
    }

    cout << endl;

    pnode = solu.ReversetList(List);

        while (pnode != NULL)
    {
        cout << pnode->m_nValue << " ";
        pnode = pnode->m_pNext;
    }

    return 0;
}
