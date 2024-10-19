#include <stdio.h>

int function(int a, int b)
{
    int counter = 0;
    int max = (a > b) ? a : b;
    int min = (a > b) ? b : a;

    if(max >= 153 && min <= 153)
        counter++;
    if(max >= 370 && min <= 370)
        counter++;
    if(max >= 371 && min <= 371)
        counter++;
    if(max >= 407 && min <= 407)
        counter++;
    if(max >= 1634 && min <= 1634)
        counter++;
    if(max >= 8208 && min <= 8208)
        counter++;
    if(max >= 9474 && min <= 9474)
        counter++;
    return counter;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", function(a, b));
    return 0;
}