#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode h = ListNode(-1);
    ListNode *p = &h;
    int flag = 0;

    while (l1 || l2)
    {
        int temp;
        if (l1 && l2)
        {
            temp = l1->val + l2->val + flag;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1)
        {
            temp = l1->val + flag;
            l1 = l1->next;
        }
        else
        {
            temp = l2->val + flag;
            l2 = l2->next;
        }

        flag = temp / 10;
        temp = temp % 10;

        p->next = new ListNode(temp);
        p = p->next;
    }

    if (flag)
    {
        p->next = new ListNode(flag);
    }

    return h.next;
}

