#include<stdio.h>
#include<math.h>
double function(double x, double a)
{
    return a * pow(x, 2) - pow(x, 3) ;
}
int main()
{
    double a = 0.0;
    double max = -100;
    scanf("%lf", &a);
    for(double i = 0.0; i <=10; i += 0.0001)
        max = (max > function(i, a))? max :function(i, a);
    printf("%.2lf\n", max);
    return 0;
}