#include <stdio.h>
#include <string.h>
int main()
{
    char domString[42] = {'\0'};
    char subString[21] = {'\0'};
    char tmpString[21] = {'\0'};
    int n;
    fgets(domString, 20, stdin);
    fgets(subString, 20, stdin);
    scanf("%d", &n);
    for (int i = 0; i < 21; i++)
    {
        if (domString[i] == ' ' || domString[i] == '\n')
            domString[i] = '\0';
        if (subString[i] == ' ' || subString[i] == '\n')
            subString[i] = '\0';
    }
    for (int i = n; domString[i]; i++)
    {
        tmpString[i - n] = domString[i];
        domString[i] = '\0';
    }
    strcat(domString, subString);
    strcat(domString, tmpString);
    puts(domString);
    return 0;
}