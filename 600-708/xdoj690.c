#include <stdio.h>
#include <stdlib.h>
int isOdd(int lower, int upper)
{
    int counter = 0;
    for (int i = lower; i <= upper; i++)
        if (i % 2)
            counter++;
    return counter;
}
int isNumber(int lower, int upper)
{
    int counter = 0;
    for (int i = lower; i <= upper; i++)
        if (!(i % 4) && (i % 3))
            counter++;
    return counter;
}
int main()
{
    int n, rsl;
    scanf("%d", &n);
    rsl = isOdd(n, n * n);
    printf("%d %d %d\n%d", rsl, n * n - n + 1 - rsl, isNumber(n, n * n), n * n - n + 1);
    return 0;
}