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
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    ListNode *dummy = new ListNode(-1), *fast = dummy, *low = dummy;
    dummy->next = head;
    while (n-- > 0)
        fast = fast->next;
    while (fast != NULL)
    {
        if(fast->next==NULL)
            low->next = low->next->next;
        else
            low = low->next;
        fast = fast->next;
    }
    return dummy->next;
}

int main()
{
    Solution s;
    int n;
    cin >> n;
    ListNode a = ListNode(-1);
    ListNode *p = &a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ListNode l_temp = ListNode(temp);
        p->next = &l_temp;
        p = p->next;
    }
    cin >> n;
    s.removeNthFromEnd(a.next, n);
    p = a.next;
    while(p)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}