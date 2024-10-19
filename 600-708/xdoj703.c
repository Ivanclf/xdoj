#include<stdio.h>
long getNumber(int n1, int n2)
{
    long counter;
    if(n1 > n2)
    {
        n1 = n1 ^ n2;
        n2 = n1 ^ n2;
        n1 = n1 ^ n2;
    }
    if(!(n2 % n1))
        return n2;
    else
        for(int i = 1; i < n1; i++)
            if(!(n1 % i) && !(n2 % i))
                counter = i;
    return (n1 / counter) * (n2 / counter) * counter;
}
int main()
{
    long rsl = 0, a[101] = {0};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    for(int i = 0; i < n - 1; i++)
        rsl += getNumber(a[i], a[i + 1]);
    printf("%ld\n", rsl);
    return 0;
}