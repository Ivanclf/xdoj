#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *map = NULL;
int *rst = NULL;

int across(int i, int n)
{
    int output = 0;
    for (int j = 0; j < n; j++)
        output += *(map + i * n + j);
    return output;
}
int endlong(int i, int n)
{
    int output = 0;
    for (int j = 0; j < n; j++)
        output += *(map + j * n + i);
    return output;
}
int diagnal(int n)
{
    int output = 0;
    for (int i = 0; i < n; i++)
        output += *(map + i * n + i);
    return output;
}
int antiDiagnal(int n)
{
    int output = 0;
    for (int i = 0; i < n; i++)
        output += *(map + i * n + (n - i - 1));
    return output;
}
void bubbleSort(int n)
{
    int temp = 0;
    for (int i = n * 2 + 2; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (j != 0 && *(rst + j - 1) < *(rst + j))
            {
                temp = *(rst + j - 1);
                *(rst + j - 1) = *(rst + j);
                *(rst + j) = temp;
            }
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    map = (int *)malloc(n * n * sizeof(int));
    rst = (int *)malloc((n * 2 + 2) * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", map + i * n + j);

    for (int i = 0; i < n; i++)
    {
        *(rst + i) = across(i, n);
        *(rst + n + i) = endlong(i, n);
    }
    *(rst + 2 * n) = diagnal(n);
    *(rst + 2 * n + 1) = antiDiagnal(n);
    bubbleSort(n);
    for (int i = 0; i < n * 2 + 2; i++)
        printf("%d ", *(rst + i));
    free(map);
    free(rst);
    return 0;
}
