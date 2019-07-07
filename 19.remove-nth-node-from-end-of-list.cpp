/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> S;
        ListNode* p = head;
        while(p)
        {
            S.push(p);
            p = p->next;
        }
        int i;
        for(i = 1;i < n;i++)
        {
            p = S.top();
            S.pop();
        }
        S.pop();
        if (S.empty())
        {
            return p;
        }
        else
        {
            ListNode* q = S.top();
            q -> next = p;
            return head;
        }
    }
};

