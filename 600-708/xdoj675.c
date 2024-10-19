//可构造三角形个数
#include <stdio.h>
#include <stdbool.h>
bool isTriangle(int n1, int  n2, int n3)
{
    if (n1 + n2 > n3 && n1 + n3 > n2 && n2 + n3 > n1)
        return true;
    return false;
}
int main()
{
    int n, counter = 0;
    int length[40] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &length[i]);

    for (int i = 0; i < n - 2; i++)
        if (isTriangle(length[i], length[i + 1], length[i + 2]))
            counter++;

    printf("%d", counter);
    return 0;
}