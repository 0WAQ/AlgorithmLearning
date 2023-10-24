#include <iostream>
#include <vector>
using namespace std;

void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) 
{
    // 如果只有一个盘子，直接移在C上
    if(n == 1)
    {
        C.push_back(A.back());
        A.pop_back();
        return;
    }

    // 将 n - 1 个盘子从A移到B上
    move(n - 1, A, C, B);

    // 将最后一个盘子从A移到C上
    C.push_back(A.back());
    A.pop_back(); 
    
    // 将 n - 1 个盘子从B移到C上
    move(n - 1, B, A, C);
}

void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
{
    int n = A.size();
    move(n, A, B, C);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A, B, C;
    for(int i = 0; i < n; i++)
    {
        A.push_back(n - i - 1);
        cout << A[i] << ' ';
    }
    cout << endl;
    hanota(A, B, C);
    for(int i = 0; i < n; i++)
        cout << C[i] << ' ';
    cout << endl;
    return 0;
}