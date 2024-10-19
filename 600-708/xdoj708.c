#include <stdio.h>
int function(int n)
{
    return 3 * (n - 1) * (n - 1) + 2 * (n - 1) + 1;
}
int main()
{
    int m;
    long sumEven = 0, sumOdd = 0;
    long tmp;
    scanf("%d", &m);
    for (int i = 7, counterOdd = 0; counterOdd < m - 1; i++)
    {
        tmp = function(i);
        if (tmp % 2 && counterOdd < m)
        {
            sumOdd += tmp;
            counterOdd++;
        }
    }
    for (int i = 8, counterEven = 0; counterEven < m; i++)
    {
        tmp = function(i);
        if (!(tmp % 2) && counterEven <= m)
        {
            sumEven += tmp;
            counterEven++;
        }
    }
    printf("%d %d", sumEven, sumOdd);
    return 0;
}