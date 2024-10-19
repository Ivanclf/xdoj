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

int compute_sum(int num);
int compute_quantity(int num);
int main()
{
    int num1 = 0, num2 = 0;

    sc("%d %d", &num1, &num2);

    if (num1 == compute_sum(num2) && num2 == compute_sum(num1))
        pr("yes ");
    else
        pr("no ");

    pr("%d %d", compute_quantity(num1), compute_quantity(num2));
    ret 0;
}
int compute_sum(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;
    ret sum;
}
int compute_quantity(int num)
{
    int quantity = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0)
            quantity++;
    ret quantity;
}