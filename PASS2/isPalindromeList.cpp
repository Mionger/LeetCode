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
    bool isPalindrome(ListNode *head);
    ListNode *reverseList(ListNode *head);
};

bool Solution::isPalindrome(ListNode *head)
{
    if(!head)
        return true;
    bool result = true;
    ListNode *dommy = new ListNode(-1);
    dommy->next = head;
    ListNode *fast = dommy->next;
    ListNode *slow = dommy->next;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *l1 = dommy->next;
    ListNode *l2 = slow->next;
    l2 = this->reverseList(l2);
    while (l1 && l2)
    {
        if(l1->val!=l2->val)
        {
            result = false;
            break;
        }
        else
        {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return result;
}

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

int main()
{
    ListNode *head = new ListNode(-1);
    int n;
    cin >> n;
    ListNode *p = head;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ListNode *node = new ListNode(temp);
        p->next = node;
        p = p->next;
    }
    p = head->next;
    while(p)
    {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
    Solution s;
    cout << s.isPalindrome(head->next) << endl;
    return 0;
}