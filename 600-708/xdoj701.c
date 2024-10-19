#include<stdio.h>
#include<math.h>
int main()
{
    int n, counter = 0;
    double avg = 0.0, square = 0.0, a[120] = {0.0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", &a[i]);
    for(int i = 0; i < n; i++)
        avg += a[i];
    avg /= n;
    for(int i = 0; i < n; i++)
        square += (a[i] - avg) * (a[i] - avg);
    square = sqrt(square / (n - 1));
    for(int i = 0; i < n; i++)
        if(a[i] < avg - 3 * square || a[i] > avg + 3 * square)
            counter++;
    printf("%.4lf %d", square, counter);
    return 0;
}