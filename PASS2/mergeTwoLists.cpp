#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
    {
        return l2;
    }

    if (!l2)
    {
        return l1;
    }

    ListNode* head = NULL;
    ListNode* cur_1 = l1;
    ListNode* cur_2 = l2;

    if (l1->val <= l2->val)
    {
        head = l1;
        cur_1 = l1->next;
    }
    else
    {
        head = l2;
        cur_2 = l2->next;
    }

    ListNode* cur = head;

    while (cur_1 != NULL && cur_2 != NULL)
    {
        if (cur_1->val <= cur_2->val)
        {
            cur->next = cur_1;
            cur_1 = cur_1->next;
        }
        else
        {
            cur->next = cur_2;
            cur_2 = cur_2->next;
        }
        cur = cur->next;
    }

    while (cur_1 != NULL)
    {
        cur->next = cur_1;
        cur = cur->next;
        cur_1 = cur_1->next;
    }

    while (cur_2 != NULL)
    {
        cur->next = cur_2;
        cur = cur->next;
        cur_2 = cur_2->next;
    }

    return head;
}