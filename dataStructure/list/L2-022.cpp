#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int data, next, prev;
};

/**
 * 模拟链表
 * 将链表的节点按照n 1 n-1 2...的顺序打印
 * 将该链表变成一个双向循环链表
*/

int main()
{
    int n, a1;
    cin >> a1 >> n;
    vector<node> a(1e5);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x >> a[x].data >> a[x].next;
        if(a[x].next == -1) {
            a[x].next = a1;
        }
        a[a[x].next].prev = x;
    }
    int l = a1, r = a[a1].prev;
    while(1)
    {
        if(l != r)
            printf("%05d %d %05d\n", r, a[r].data, l);
        else
        {
            printf("%05d %d -1\n", r, a[r].data);
            break;
        }

        if(a[r].prev != l)
            printf("%05d %d %05d\n", l, a[l].data, a[r].prev);
        else
        {
            printf("%05d %d -1\n", l, a[l].data);
            break;
        }

        r = a[r].prev;
        l = a[l].next;
    }
    return 0;
}