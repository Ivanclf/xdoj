#include<stdio.h>
#define none '\0'
char original[10000] = {none};
int sieveString()
{
    int counter = 0;
    for(int i = 0; original[i] || original[i + 1] || original[i + 2]; i++)
    {
        if((original[i] >= 'a' && original[i] <= 'z')||(original[i] >= 'A' && original[i] <= 'Z'))
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    char ch = none;
    for(int i = 0; ; i++)
    {
        ch = getchar();
        if(ch == EOF)
            break;
        else
            original[i] = ch;
    }
    printf("%d\n", sieveString());
    return 0;
}