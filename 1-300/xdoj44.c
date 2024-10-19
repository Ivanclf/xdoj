#include<stdio.h>
#include<stdbool.h>

int fibonacci(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
bool pCheck(int n)
{
    bool b = false;
    for(int i = 2; i <= n / 2; i++)
    {
        if(!(n % i))
        {
            b = true;
            return false;
        }
    }
    if(b == false)
        return true;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    pCheck(fibonacci(n))?(printf("yes")):(printf("%d\n", fibonacci(n)));
    return 0;
}
