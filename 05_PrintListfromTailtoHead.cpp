#include<iostream>
#include<stack>
#include<vector>


using namespace std;

//创建单链表节点
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

/*=======================在单向链表尾增添元素==========================*/

//考虑如果链表本身为空的时候，添加元素则新添加元素赋给pHead，
//如果不用二重指针，则在函数外不能改变*pHead的指向
void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();    //使用new创建对象
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if (*pHead == NULL)     //如果链表为空，则直接赋值
        *pHead = pNew;
    else
    {
        ListNode* pNode = *pHead;   //链表不为空，则通过移动指针pNode至最后
        while (pNode->m_pNext != NULL)
        {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = pNew;  //添加元素
    }
}

/*=====================删除给定值节点=================================*/
void RemoveNode(ListNode** pHead, int value)
{
    if (*pHead == NULL || pHead == NULL)      //
        return;

    ListNode* pToBeDeleted = NULL;  //临时节点

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
        delete pToBeDeleted;     //释放内存
        pToBeDeleted = NULL;     //释放指针
    }
}

/*=========================测试类与main函数======================*/

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


/*===========================从尾到头打印链表========================*/
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

/*======================递归方式=====================*/
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


