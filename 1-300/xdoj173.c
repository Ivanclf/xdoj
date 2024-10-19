#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int command[110] = {0};
bool train[20][5] = {false};
void tickieChoose(int quantity)
{
    int emptySeat = 0;
    int k = 0;
    for (int i = 0;; i++)
    {
        emptySeat = 0;
        k = 0;
        for (int j = 0; j < 5; j++)
        {
            if (train[i][j] == false)
                emptySeat++;
        }
        if (emptySeat >= quantity)
        {
            for (int j = 0; j < 5; j++)
            {
                if (train[i][j] == false)
                {
                    printf("%d ", i * 5 + j + 1);
                    train[i][j] = true;
                    k++;
                }
                if (k == quantity)
                    break;
            }
            printf("\n");
            break;
        }
        else if (i == 19)
        {
            i = 0;
            for (i = 0;; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (train[i][j] == false)
                    {
                        printf("%d ", i * 5 + j + 1);
                        train[i][j] = true;
                        k++;
                    }
                    if (k == quantity)
                    {
                        printf("\n");
                        goto L;
                    }
                }
            }
        }
    }
L:;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &command[i]);
    for (int i = 0; i < n; i++)
        tickieChoose(command[i]);
    return 0;
}