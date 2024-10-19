#include <stdio.h>
int main()
{
    int n, temp, a[500];
    for(int i = 0; i < 500; i++)
        a[i] = -1;
    scanf("%d %d %d", &a[0], &a[1], &n);
    for (int i = 0; i < n; i++)
    {
        temp = a[i] * a[i + 1];
        for (int j = 0; temp + 1; j++)
        {
            if (a[i + j] + 1)
                continue;
            if (i + j > n)
            {
                for (int k = 0; k < n; k++)
                    printf("%d ", a[k]);
                return 0;
            }
            if (temp < 10)
            {
                a[i + j] = temp;
                break;
            }
            else
            {
                a[i + j] = temp / 10;
                a[i + j + 1] = temp % 10;
                break;
            }
        }
    }
    for (int i = 0; a[i]; i++)
        printf("%d ", a[i]);
    return 0;
}