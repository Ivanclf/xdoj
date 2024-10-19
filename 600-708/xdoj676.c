#include<stdio.h>
#include<stdlib.h>
int main()
{
    char string[100] = {'\0'};
    for(int i = 0; ; i++)
    {
        string[i] = getchar();
        if(string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
    }
    for(int i = 0; string[i]; i++)
    {
        if((string[i] >= 'a' && string[i] <= 'm') || (string[i] >= 'A' && string[i] <= 'M'))
            string[i] += 13;
        else if ((string[i] >= 'n' && string[i] <= 'z') || (string[i] >= 'N' && string[i] <= 'Z'))
            string[i] -= 13;
    }
    printf("%s\n", string);
    return 0;
}