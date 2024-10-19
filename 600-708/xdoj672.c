//计算正弦函数
#include <stdio.h>
#include <math.h>
long long mutiply(int n)
{
    long long result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}
int main()
{
    int n = 0;
    double x = 0.0;
    double rsl = 0.0;
    scanf("%d %lf", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        if(i % 2)
            rsl += (pow(x, (double)(2 * i - 1)) / (double)mutiply(2 * i - 1));
        else
            rsl -= (pow(x, (double)(2 * i - 1)) / (double)mutiply(2 * i - 1));
    }
    printf("%.4lf\n", rsl);
}