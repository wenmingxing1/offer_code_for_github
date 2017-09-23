#include<iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, int k)
{
    if (pListHead == NULL)  //如果输入链表
        return NULL;
    if (k == 0)     //如果k==0
        return NULL;

    ListNode* pAhead = pListHead;
    ListNode* pBehind = pListHead;

    for (int i = 0; i < k - 1; ++i)
    {
        if (pAhead->m_pNext != NULL)      //判断不能让输入的k值小于链表长度
        {
            pAhead = pAhead->m_pNext;
        }
        else
        {
            return NULL;
        }
    }

    while (pAhead->m_pNext != NULL)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

int main()
{
    //->运算符需要前面是指针（指向类对象的指针），.运算符需要前面是类的对象。
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

    cout << FindKthToTail(List, 2)->m_nValue << endl;

    return 0;
}
