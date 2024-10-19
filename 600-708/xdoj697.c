#include<stdio.h>
int main()
{
    double distance, price;
    int time;
    scanf("%lf %d", &distance, &time);
    if(distance - 3.0 <= 0)
        price += 10;
    else if (distance <= 10)
        price += 10 + (distance - 3) * 2;
    else
        price += 24 + (distance - 10) * 3;
    if(time)
        price += time / 5 * 2;
    printf("%.1lf", price);
    return 0;
}