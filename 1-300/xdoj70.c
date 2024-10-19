#include <stdio.h>
#include <stdlib.h>

int *twoDimensionArray = NULL;
int *oneDimensionArray = NULL;

int add(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
        result += i;
    return result;
}

void zigzagScan(int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!i)
            *oneDimensionArray = *twoDimensionArray;
        else if (i % 2) // odd number
        {
            temp = add(i);
            for (int j = 0; j <= i; j++)
            {
                *(oneDimensionArray + temp + j) = *(twoDimensionArray + j * n + (i - j));
            }
        }
        else // even number
        {
            temp = add(i);
            for (int j = 0; j <= i; j++)
            {
                *(oneDimensionArray + temp + j) = *(twoDimensionArray + (i - j) * n + j);
            }
        }
    }
    for (int i = n; i <= (n - 1) * 2; i++)
    {
        if (i == (n - 1) * 2)
        {
            temp = add(n) + add(n - 1) - 1;
            *(oneDimensionArray + temp) = *(twoDimensionArray + (n - 1) * n + n - 1);
        }
        else if (!(i % 2)) // even number
        {
            temp = add(n) + add(n - 1) - add(2 * n - i - 1);
            for (int j = 0; j <= 2 * n - i - 2; j++)
            {
                *(oneDimensionArray + temp + j) = *(twoDimensionArray + (n - 1 - j) * n + (i - (n - 1 - j)));
            }
        }
        else // odd number
        {
            temp = add(n) + add(n - 1) - add(2 * n - i - 1);
            for (int j = 0; j <= 2 * n - i - 2; j++)
            {
                *(oneDimensionArray + temp + j) = *(twoDimensionArray + (i - (n - 1 - j)) * n + (n - 1 - j));
            }
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    oneDimensionArray = (int *)malloc(n * n * sizeof(int));
    twoDimensionArray = (int *)malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", twoDimensionArray + i * n + j);
    zigzagScan(n);
    for (int i = 0; i < n * n; i++)
        printf("%d ", *(oneDimensionArray + i));
    free(oneDimensionArray);
    free(twoDimensionArray);
    return 0;
}