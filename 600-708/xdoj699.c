#include <stdio.h>
int main()
{
    int quantity, number, max = -1, min = 30, score[21] = {0};
    float avg = 0;
    scanf("%d %d", &quantity, &number);
    for (int i = 0; i < quantity; i++)
        scanf("%d", &score[i]);
    for (int i = 0; i < quantity; i++)
    {
        avg += score[i];
        max = max > score[i] ? max : score[i];
        min = min > score[i] ? score[i] : min;
    }
    if (score[number - 1] == max)
    {
        avg -= min;
        printf("%.2f", avg / (quantity - 1));
    }
    else if (score[number - 1] == min)
    {
        avg -= max;
        printf("%.2f", avg / (quantity - 1));
    }
    else
    {
        avg -= (max + min);
        printf("%.2f", avg / (quantity - 2));
    }
    return 0;
}