/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;

        ListNode* q = newhead;
        ListNode* p = head;
        while(p && p->next)
        {
            ListNode* s = p;
            ListNode* t = p->next;
            
            q->next = t;
            s->next = t->next;
            t->next = s;
            
            p = s->next;
            q = s;
        }

        return newhead->next;
    }
};

