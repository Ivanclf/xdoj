#include<stdio.h>
#include<stdbool.h>
bool isLeapYear(int year)
{
    if((!(year % 4) && year % 100) || !(year % 400))
        return true;
    return false;
}
int main()
{
    int year, month, day;
    int result = 0;
    const int monList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d,%d,%d", &year, &month, &day);
    for(int i = 0; i < month - 1; i++)
    {
        result += monList[i];
        if(i == 1 && isLeapYear(year))
            result++;
    }
    result += day;
    printf("%d", result);
}