#include<stdio.h>
#include<stdlib.h>

int culculate(int number)
{
    int counter = 0;
    for(int i = 1; number; i++)
    {
        counter += number % 10;
        number /= 10;
    }
    return counter;
}
int main()
{
    int array[25] = {0};
    int n, counter = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for(int i = 0; i < n; i++)
        counter += culculate(array[i]);
    printf("%d", counter % 10);
    return 0;
}