#include <stdio.h>
int main()
{
    int n, a[30] = {0};
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < n - i; j++)
            if (a[j] > a[j + 1])
            {
                a[j] = a[j] ^ a[j + 1];
                a[j + 1] = a[j] ^ a[j + 1];
                a[j] = a[j] ^ a[j + 1];
            }
    for (int i = 0; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}