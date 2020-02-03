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
    bool hasCycle(ListNode *head);
};

bool Solution::hasCycle(ListNode *head)
{
    if(!head)
        return false;
    bool result = true;
    ListNode *slow = head;
    ListNode *fast = head;
    while(true)
    {
        if (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                result = true;
                break;
            }
        }
        else
        {
            result = false;
            break;
        }
    }
    return result;
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
        if (!p->next)
        {
            cout << p->val << ' ';
            p->next = head->next;
            break;
        }
    }
    cout << endl;
    Solution s;
    cout << s.hasCycle(head->next) << endl;
    return 0;
}