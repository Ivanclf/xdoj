#include <stdio.h>
#include <stdlib.h>
#define ll long long

int intpow(int redix, int index)
{
    int result = 1;
    for (int i = 1; i <= index; i++)
    {
        result *= redix;
    }
    return result;
}
int main()
{
    ll input = 0;
    ll tmp = 0;
    ll swop = 0;
    int digit = 0;

    scanf("%lld", &input);
    if (input < 10)
    {
        printf("%lld", input);
        return 0;
    }
    tmp = input;
    for (; tmp != 0; digit++)
    {
        tmp /= 10;
    }
    tmp = input;
    for (int i = 1; i <= digit; i++)
    {
        if (i == 1)
        {
            swop = intpow(10, digit - i) * (tmp % intpow(10, i));
            printf("%lld\n", swop);
        }
        else
        {
            swop += intpow(10, digit - i) * (tmp % intpow(10, i) - tmp % intpow(10, i - 1)) / intpow(10, i - 1);
            printf("%lld\n", swop);
        }
    }
    if (swop == input)
        printf("%lld", input);
    else
        printf("no");
    return 0;
}