#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

class Solution
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;

        ListNode* pNewHead = NULL;

        if (pHead1->val <= pHead2->val)
        {
            pNewHead = pHead1;
            pNewHead->next = Merge(pHead1->next, pHead2);
        }
        if (pHead1->val > pHead2->val)
        {
            pNewHead = pHead2;
            pNewHead->next = Merge(pHead1, pHead2->next);
        }
        return pNewHead;
    }
};

int main()
{
    ListNode List1[3];
    ListNode List2[3];

    List1[0].val = 1;
    List1[0].next = &List1[1];
    List1[1].val = 3;
    List1[1].next = &List1[2];
    List1[2].val = 5;
    List1[2].next = NULL;

    List2[0].val = 2;
    List2[0].next = &List2[1];
    List2[1].val = 4;
    List2[1].next = &List2[2];
    List2[2].val = 6;
    List2[2].next = NULL;

    Solution solu;

    ListNode* node = solu.Merge(List1, List2);

    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    return 0;
}
