#include<stdio.h>

int main()
{
    int min, max;
    int tmp = 0;
    scanf("%d %d", &min, &max);
    for(int i = min; i <= max; i++)
    {
        if(i == 1)
            continue;
        tmp = 0;
        for(int j = 1; j < i; j++)
        {
            if(i % j == 0)
            {
                tmp += j;
            }
        }
        if(i == tmp)
            printf("%d ", i);
    }
    return 0;
}