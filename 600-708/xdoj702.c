#include<stdio.h>
int main()
{
    int n, a[1010] = {-1}, time = 0, temp = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        if(a[i + 1] - a[i])
        {
            temp++;
            time = time < temp ? temp : time;
            temp = 0;
            continue;
        }
        temp++;
    }
    printf("%d", time);
    return 0;
}