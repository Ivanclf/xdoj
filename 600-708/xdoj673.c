//判断同构数
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int digit(long long n)
{
    int result = 0;
    for (int i = 10;;)
    {
        if (n)
        {
            n /= i;
            result++;
            continue;
        }
        return result;
    }
}
bool isNumber(long long n)
{
    long long temp = 0;
    long long tenRedix;
    int di = digit(n);
    for (int i = 0; i <= di / 2 + 1; i++)
    {
        tenRedix = 1;
        for (int j = 0; j < i; j++)
            tenRedix *= 10;
        temp = n % tenRedix;
        if (temp * temp == n)
            return true;
    }
    return false;
}
int main()
{
    long long n = 0;
    scanf("%lld", &n);
    for(int i = 1; i < n; i++)
    if(isNumber(i))
    printf("%lld %d\n", i, isNumber(i));
    return 0;
}