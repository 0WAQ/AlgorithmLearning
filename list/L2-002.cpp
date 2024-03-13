// 天梯赛题目集：L2-002，链表去重：https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805072641245184?type=7&page=0
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
struct node
{
    int data;
    int next;
}list[N];

// 存的是地址
vector<int> del;
vector<int> stop;
bool st[N];

int main()
{
    int head, n;
    cin >> head >> n;

    for(int i = 1; i <= n; i++)
    {
        int ad;
        cin >> ad;
        cin >> list[ad].data >> list[ad].next;
    }

    // 模拟链表操作
    int i = head;
    while(i != -1)
    {
        int x = abs(list[i].data);

        if(!st[x])
            stop.emplace_back(i), st[x] = true;
        else
            del.emplace_back(i);

        i = list[i].next;
    }

    // 输出
    for(i = 0; i < stop.size() - 1; i++)
        printf("%05d %d %05d\n", stop[i], list[stop[i]].data, stop[i + 1]);
    printf("%05d %d -1\n", stop[i], list[stop[i]].data);

    if(del.size())
    {
        for(i = 0; i < del.size() - 1; i++)
            printf("%05d %d %05d\n", del[i], list[del[i]].data, del[i + 1]);
        printf("%05d %d -1\n", del[i], list[del[i]].data);
    }
    return 0;
}