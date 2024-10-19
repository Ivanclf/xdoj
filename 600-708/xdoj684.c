#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main()
{
    double x, r, xNext;
    scanf("%lf %lf", &x, &r);
    for (int i = 0; i <= 1000; i++)
    {
        xNext = r * x * (1 - x);
        if (fabsl(xNext - x) < 0.00001)
        {
            printf("%.4lf 1", xNext);
            return 0;
        }
        x = xNext;
    }
    printf("%.4lf 0", xNext);
    return 0;
}