#include <stdio.h>
#include<string.h>
int i = 0, j = 0;
int getLength(char string[])
{
    int result = 0;
    for (i = 0; string[i] != '\0'; i++)
        result++;
    return result - 1;
}
int main()
{
    int status, g = 0;
    char domString[30] = {'\0'};
    char subString[30] = {'\0'};
    gets(domString);
    gets(subString);
    int lengthDom = strlen(domString);
    int lengthSub = strlen(subString);
    
    for (i = 0; i < lengthDom; i++)
    {
        status = 1;
        for (j = 0; j < lengthSub; j++)
        {
            if (domString[i + j] == subString[j])
                status *= 1;
            else
                status *= 0;
        }
        if (status)
        {
            printf("%d ", i + 1);
            g++;
        }
    }
    if (!g)
        printf("No!");
    return 0;
}
