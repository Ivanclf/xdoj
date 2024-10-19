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

int main()
{
    int n = 0, k = 0;
    int arr[114514] = {0};
    int status = false;

    sc("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        sc("%d", &arr[i]);
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == k)
        {
            pr("%d ", i);
            status = true;
        }
    }
    if(status == false)
        pr("-1\n");
    ret 0;
}