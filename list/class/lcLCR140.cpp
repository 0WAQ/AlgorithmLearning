#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *trainingPlan(ListNode *head, int cnt)
{
    cnt--;
    ListNode* f = head, *s = head;
    while(f && f->next)
    {
        if(cnt)
        {
            f = f->next;
            --cnt;
            continue;
        }
        f = f->next;
        s = s->next;
    }
    return s;
}

int main()
{
    ListNode* l = nullptr, *r = nullptr;
    int n, x, cnt;
    cin >> n >> cnt;
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
    ListNode* ans = trainingPlan(l, cnt);
    cout << ans->val << endl;
    return 0;
}