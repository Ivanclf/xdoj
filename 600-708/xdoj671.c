//方差计算
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double avg(int *data, int quantity)
{
    double total = 0;
    for(int i = 0; i < quantity; i++)
        total += *(data + i);
    total /= quantity;
    return total;
}
int main()
{
    int *data = NULL;
    int quantity = 0;
    double average = 0.0;
    double rsl = 0.0;

    scanf("%d", &quantity);
    data = (int *)malloc(quantity * sizeof(int));
    for(int i = 0; i < quantity; i++)
        scanf("%d", data + i);
    average = avg(data, quantity);
    for(int i = 0; i < quantity; i++)
        rsl += pow((double)*(data + i) - average, 2);
    rsl /= quantity;
    printf("%d\n", (int)rsl);
    free(data);
    return 0;
}