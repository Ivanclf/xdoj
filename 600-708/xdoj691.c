#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, a[40] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n % 2)
        for (int i = 0; i < n / 2; i++)
        {
            a[i] = a[i] ^ a[n / 2 + 1 + i];
            a[n / 2 + 1 + i] = a[i] ^ a[n / 2 + 1 + i];
            a[i] = a[i] ^ a[n / 2 + 1 + i];
        }
    else
        for (int i = 0; i < n / 2; i++)
        {
            a[i] = a[i] ^ a[n / 2 + i];
            a[n / 2 + i] = a[i] ^ a[n / 2 + i];
            a[i] = a[i] ^ a[n / 2 + i];
        }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}