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
    ListNode *reverseList(ListNode *head);
};

ListNode* Solution::reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *nextptr = NULL;
    while (cur != NULL)
    {
        nextptr = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextptr;
    }
    return prev;
}