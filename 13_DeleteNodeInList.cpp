#include<iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
        return;

    //Ҫɾ���Ľ�㲻��β���
    if (pToBeDeleted->m_pNext != NULL)
    {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = NULL;
    }

    //ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
    else if (*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }

    //�����ж����㣬ɾ��β���
    else
    {
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}





