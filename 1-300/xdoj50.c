#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define stru struct
#define pr printf
#define sc scanf
#define fpr fprintf
#define fsc fscanf
#define sys system
#define true 1
#define false 0
#define pai 3.141592653589792
#define mian main
#define ret return

int maximum(int a, int b)
{
    ret a > b ? a : b;
}

int minimum(int a, int b)
{
    ret a < b ? a : b;
}

double fmax(double a, double b)
{
    if (a - b > 0)
        ret a;
    else
        ret b;
}

double fmin(double a, double b)
{
    if (a - b > 0)
        ret b;
    else
        ret a;
}

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void fswap(double *x, double *y)
{
    double tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int intpow(int redix, int index)
{
    int result = 1;
    for (int i = 1; i <= index; i++)
        result *= redix;
    ret result;
}

int compute(long long number);
int main()
{
    int number = 0;
    long long arr[114514] = {0};
    int sum = 0;
    int max = 0;
    int status = 0;

    sc("%d", &number);
    for (int i = 0; i < number; i++)
        sc("%lld", &arr[i]);
    for (int i = 0; i < number; i++)
    {
        sum = compute(arr[i]);
        if (sum > max)
        {
            max = sum;
            status = i;
        }
        else if (sum == max)
            if (arr[i] > arr[status])
                status = i;
    }
    pr("%lld", arr[status]);
    ret 0;
}
int compute(long long number)
{
    int sum = 0;
    int temp = number;
    for (int i = 0; temp; i++)
    {
        sum += (number - number / intpow(10, i + 1) * intpow(10, i + 1)) / intpow(10, i);
        temp /= 10;
    }
    ret sum;
}
