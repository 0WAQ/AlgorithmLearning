#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode* f = head, *s = head, *p = head;
    while(f)
    {
        s = s->next;
        if(f->next == nullptr)
            return nullptr;
        f = f->next->next;

        // 如果相遇
        if(f == s)
        {
            while(p != s)
            {
                p = p->next;
                s = s->next;
            }
            return p;
        }
    }
    return nullptr;
}

int main()
{
    ListNode* l = nullptr, *r = nullptr;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        ListNode* t = new ListNode(x);
        if(!i)
        {
            l = r = t;
        }
        else
        {
            r->next = t;
            r = t;
        }
    }
    cin >> x;
    ListNode* s = l;
    while(x)
    {
        s = s->next;
        x--;
    }
    r->next = s;

    ListNode* ans = detectCycle(l);
    if(!ans)
        cout << "NULL" << endl;
    else
        cout << ans->val << endl;
    return 0;
}
