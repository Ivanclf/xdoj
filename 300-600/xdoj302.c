#include<stdio.h>

int main()
{
    int n = 0, m = 2;
    int i = 0, j = 0;
    int re = 0;
    scanf("%d", &n);
    for(i = 2; ; i++)
    {
        for(j = 2; j <= i / 2; j++)
        {
            if(i % j == 0)
                break;
            else if(j == i / 2)
            {
                m++;
                if(m >= n && m <= n + 10)
                {
                    re += i;
                }
        }
        }
        if(m > n + 10)
            break;
    }
    printf("%d", re);
    return 0;
}