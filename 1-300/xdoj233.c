#include<stdio.h>
#include<string.h>
int main()
{
    char a[55] = {'\0'};
    int n;
    gets(a);
    scanf("%d", &n);
    int length = strlen(a);
    if(n > length)
    {
        printf("error");
        return 0;
    }
    for(int i = n - 1; a[i]; i++)
        printf("%c", a[i]);
    return 0;
}