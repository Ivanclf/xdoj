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

char output(int score);
int main()
{
    int score = 0;
    sc("%d", &score);
    pr("%c", output(score));
}
char output(int score)
{
    switch (score / 10)
    {
    case 10:
    case 9:
        ret 'A';
        break;
    case 8:
        ret 'B';
        break;
    case 7:
        ret 'C';
        break;
    case 6:
        ret 'D';
        break;
    default:
        ret 'E';
        break;
    }
}