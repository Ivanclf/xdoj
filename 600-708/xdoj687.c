#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, array[60] = {0}, sum = 0, tempmax, tempmin;
    int max = -1, min = 2e6;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for(int i = 0; i < n; i++)
    {
        sum += array[i];
        if(max < array[i])
        {
            tempmax = i + 1;
            max = array[i];
        }
        if(min > array[i])
        {
            tempmin = i + 1;
            min = array[i];
        }
    }
    printf("%d %d %d %d %d", sum, max, tempmax, min, tempmin);
    return 0;
}