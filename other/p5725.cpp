#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n * n; i++)
    {
        if(i <= 9)
            printf("0");
        printf("%d", i);
        if(i % n == 0)
            printf("\n");
    }

    cout << endl;
    
    int s = 0;
    for(int i = 1; i <= n; i++)
        s += i;
    
    int i = 1, j = 1;
    while(i <= s)
    {
        int k = 1;
        for(int l = 1; l <= n - j; l++)
            printf("  ");  
        while(k <= j)
        {
            if(i <= 9)
                printf("0");
            printf("%d", i);
            i++, k++;
        }
        j++;
        printf("\n");
    }
    return 0;
}