#include <iostream>
#include <cmath>
int isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    m = (int)pow(2, n) - 1;
    printf("%d %d\n", m, isPrime(m));
    return 0;
}