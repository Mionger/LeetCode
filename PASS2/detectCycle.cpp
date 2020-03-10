#include<iostream>
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
    ListNode *detectCycle(ListNode *head);
};

ListNode *Solution::detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }

    if (fast == NULL || fast->next == NULL || fast->next->next == NULL)
        return NULL;

    ListNode *temp = head;
    while (temp != fast)
    {
        fast = fast->next;
        temp = temp->next;
    }
    return fast;
}