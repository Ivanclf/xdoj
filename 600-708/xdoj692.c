#include <stdio.h>
int isNumber(int lower, int upper, int number)
{
    int counter = 0;
    for (int i = lower; i <= upper; i++)
        if (!(i % number))
            counter++;
    return counter;
}
int isOddNumber(int lower, int upper)
{
    int counter = 0;
    for (int i = lower; i <= upper; i++)
        if (!(i % 5) && (i % 2))
            counter++;
    return counter;
}
int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if (n1 > n2)
    {
        n1 = n1 ^ n2;
        n2 = n1 ^ n2;
        n1 = n1 ^ n2;
    }
    printf("%d %d %d\n%d", isNumber(n1, n2, 3), isNumber(n1, n2, 4), isOddNumber(n1, n2), isNumber(n1, n2, 4));
    return 0;
}