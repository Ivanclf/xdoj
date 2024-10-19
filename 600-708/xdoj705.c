#include<stdio.h>
int intpow(int redix, int index)
{
    int result = 1;
    for(int i = 0; i < index; i++)
        result *= redix;
    return result;
}
int main()
{
    int n, m;
    int a[65] = {0};
    scanf("%d %d", &n, &m);
    int times = intpow(2, n);
    for(int i = 0; i < times; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)
    {
        times = intpow(2, n - i);
        for(int j = 0; j <= times; j++)
        {
            a[j] += a[times - j - 1];
        }
    }
    times = intpow(2, n - m);
    for(int i = 0; i < times; i++)
        printf("%d ", a[i]);
    return 0;
}