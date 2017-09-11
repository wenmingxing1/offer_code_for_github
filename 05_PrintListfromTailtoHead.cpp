#include<iostream>
#include<stack>
#include<vector>


using namespace std;

//����������ڵ�
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

/*=======================�ڵ�������β����Ԫ��==========================*/

//�������������Ϊ�յ�ʱ�����Ԫ���������Ԫ�ظ���pHead��
//������ö���ָ�룬���ں����ⲻ�ܸı�*pHead��ָ��
void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();    //ʹ��new��������
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if (*pHead == NULL)     //�������Ϊ�գ���ֱ�Ӹ�ֵ
        *pHead = pNew;
    else
    {
        ListNode* pNode = *pHead;   //����Ϊ�գ���ͨ���ƶ�ָ��pNode�����
        while (pNode->m_pNext != NULL)
        {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = pNew;  //���Ԫ��
    }
}

/*=====================ɾ������ֵ�ڵ�=================================*/
void RemoveNode(ListNode** pHead, int value)
{
    if (*pHead == NULL || pHead == NULL)      //
        return;

    ListNode* pToBeDeleted = NULL;  //��ʱ�ڵ�

    if ((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;

        if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if (pToBeDeleted != NULL)
    {
        delete pToBeDeleted;     //�ͷ��ڴ�
        pToBeDeleted = NULL;     //�ͷ�ָ��
    }
}

/*=========================��������main����======================*/

/*
class Solution
{
public:
    vector<int> res;
    vector<int> PrintListFromTailToHead(ListNode *pHead)
    {
        if (pHead != NULL)
        {
            if (pHead->m_pNext != NULL)
            {
                PrintListFromTailToHead(pHead->m_pNext);
            }
            res.push_back(pHead->m_nValue);
        }
        return res;
    }
};

int main()
{
    ListNode list[4];
    list[0].m_nValue = 1;
    list[0].m_pNext = &list[1];
    list[1].m_nValue = 2;
    list[1].m_pNext = &list[2];
    list[2].m_nValue = 3;
    list[2].m_pNext = &list[3];
    list[3].m_nValue = 4;
    list[3].m_pNext = NULL;

    ListNode *node = *head;


    Solution result;
    vector<int> res = result.PrintListFromTailToHead(node);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }

    return 0;

}
*/


/*===========================��β��ͷ��ӡ����========================*/
void PrintListfromTailtoHead(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nValue << " ";
        nodes.pop();
    }
}

/*======================�ݹ鷽ʽ=====================*/
void PrintListfromTailtoHead_Recursively(ListNode* pHead)
{
    if (pHead != NULL)
    {
        if (pHead->m_pNext != NULL)
        {
            PrintListfromTailtoHead_Recursively(pHead->m_pNext);
        }
        cout << pHead->m_nValue << " ";
    }
}


