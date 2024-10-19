#include <stdio.h>

double p(double x, int n)
{
    if (!n)
        return 1;
    else if (n == 1)
        return x;
    else
        return ((2 * n - 1) * p(x, n - 1) * x - (n - 1) * p(x, n - 2)) / (n * 1.0);
}
int main()
{
    int n;
    double x;
    double rsl = 0.0;

    scanf("%d %lf", &n, &x);

    for(int i = 1; i <= n; i++)
        rsl += p(x, i);
    printf("%.4lf", rsl);

    return 0;
}