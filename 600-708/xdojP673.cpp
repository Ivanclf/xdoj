#include <stdio.h>
#include <math.h>

int main()
{
    int n, temp, digits = 0;
    scanf("%d", &n);
    temp = n;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    printf("%d ", n);
    if ((n * n - n) % (int)pow(10, digits) == 0)
        printf("1");
    else
        printf("0");

    return 0;
}