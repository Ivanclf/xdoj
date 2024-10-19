#include <stdio.h>
int average(int x1, int x2, int x3)
{
    return (x1 + x2 + x3) / 3;
}
int main()
{
    int n;
    int line[35] = {0};
    int rsl[35] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &line[i]);
    for (int i = 0; i < n; i++)
    {
        if (!i)
            rsl[i] = average(line[0], line[1], line[2]);
        else if (i == n - 1)
            rsl[i] = average(line[n - 3], line[n - 2], line[n - 1]);

        else
            rsl[i] = average(line[i - 1], line[i], line[i + 1]);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", rsl[i]);
    return 0;
}