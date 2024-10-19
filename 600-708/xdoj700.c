#include <stdio.h>
int main()
{
    int n, oddAdd = 0, evenAdd = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
            oddAdd += i;
        else
            evenAdd += i;
    }
    printf("%d %d", oddAdd, evenAdd);
    return 0;
}