#include <stdio.h>
int culculate(int n)
{
    switch (n)
    {
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return n * n + n - 4;
    }
}
int main()
{
    int m, k, reminderZero = 0, reminderOne = 0, reminderOther = 0;
    scanf("%d %d", &m, &k);
    for(int i = 1; i <= k; i++)
    {
        switch (culculate(i) % m)
        {
        case 0:
            reminderZero++;
            break;
        case 1:
            reminderOne++;
            break;
        default:
            reminderOther++;
        }
    }
    printf("%d %d %d", reminderZero, reminderOne, reminderOther);
    return 0;
}