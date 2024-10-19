#include <stdio.h>
int isArrithmaticArray(int n, int array[])
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        if (!i)
            temp = array[1] - array[0];
        else if (array[i + 1] - array[i] != temp)
            return 0;
    }
    return 1;
}
int main()
{
    int a[101] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b[101][2] = {0};
    for (int i = 0; i < n; i++)
    {
        b[i][0] = a[i];
        b[i][1] = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                a[j] = a[j] ^ a[j + 1];
                a[j + 1] = a[j] ^ a[j + 1];
                a[j] = a[j] ^ a[j + 1];
            }
    if (isArrithmaticArray(n, a))
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (b[j][0] > b[j + 1][0])
                {
                    b[j][0] = b[j][0] ^ b[j + 1][0];
                    b[j][1] = b[j][1] ^ b[j + 1][1];
                    b[j + 1][0] = b[j][0] ^ b[j + 1][0];
                    b[j + 1][1] = b[j][1] ^ b[j + 1][1];
                    b[j][0] = b[j][0] ^ b[j + 1][0];
                    b[j][1] = b[j][1] ^ b[j + 1][1];
                }
        for (int i = 0; i < n; i++)
            printf("%d ", b[i][1] + 1);
    }
    else
    {
        int min = 7e5, max = -7e5;
        for (int i = 0; i < n - 1; i++)
        {
            min = min > a[i + 1] - a[i] ? a[i + 1] - a[i] : min;
            max = max > a[i + 1] - a[i] ? max : a[i + 1] - a[i];
        }
        printf("%d %d", max, min);
    }
    return 0;
}