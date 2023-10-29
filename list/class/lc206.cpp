#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

};

ListNode* reverseList(ListNode* head) 
{
    ListNode* l = nullptr, *r = head;
    while (r)
    {
        ListNode* temp = r->next;
        r->next = l;
        l = r, r = temp;
    }
    return l;
}

int main()
{
    int n, x;
    cin >> n;
    ListNode* l = nullptr, *r = nullptr;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        ListNode* s = new ListNode;
        s->val = x;
        s->next = nullptr;
        if(!i)
            l = r = s;
        else
        {
            r->next = s;
            r = s;  
        }    
    }

    l = reverseList(l);

    while(l)
    {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
    return 0;
}