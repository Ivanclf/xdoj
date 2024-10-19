#include<cmath>
#include<iostream>
int signalNumberone(int x, int y)
{
    return (int)pow(x - 4, 2) + (int)pow(y - 4, 2);
}
int signalNumbertwo(int x, int y)
{
    return (int)pow(x + 4, 2) + (int)pow(y + 4, 2);
}
int main()
{
    int n;
    int axis[25][2] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &axis[i][0], &axis[i][1]);

    for(int i = 0; i < n; i++)
    {
        if(signalNumberone(axis[i][0], axis[i][1]) > signalNumbertwo(axis[i][0], axis[i][1]))
            printf("2");
        else
            printf("1");
        if(i != n - 1)
            printf(" ");
    }

    return 0;
}