#include<stdio.h>
#include<stdbool.h>

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
    pCheck(n)?(printf("YES\n")):(printf("NO\n"));
    return 0;
}
