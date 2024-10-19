#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    bool isSame = true;
    char string[55] = {'\0'};
    gets(string);
    int length = strlen(string);
    for(int i = 0; i < length / 2; i++)
        if(string[i] != string[length - 1 - i])
            isSame = false;
    if(isSame)
        printf("yes");
    else
        printf("no");
    return 0;
}