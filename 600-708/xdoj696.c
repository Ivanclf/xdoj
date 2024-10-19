#include<stdio.h>
int main()
{
    int n, a[25] = {0}, min = 2e5, max = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        max = max > a[i] ? max : a[i];
        min = min > a[i] ? a[i] : min;
    }
    for(int i = 0; i < n; i++)
    {
        if(max == a[i] && i != n - 1)
        {
            a[i] = a[i] ^ a[n - 1];
            a[n - 1] = a[i] ^ a[n - 1];
            a[i] = a[i] ^ a[n - 1];
        }
        if(min == a[i]  && i != 0)
        {
            a[i] = a[i] ^ a[0];
            a[0] = a[i] ^ a[0];
            a[i] = a[i] ^ a[0];
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}