#include<stdio.h>
#include<stdlib.h>

int lengthGet(char arr[])
{
    int counter = 0;
    for(int i = 0; ; i++)
    {
        if(arr[i] == '\n' || arr[i] == '\0')
            return counter;
        counter++;
    }
    
}
void bubbleSort(char arr[], int length)
{
    for(int i = 0; i < length; i++)
        for(int j = 0; j < length - i - 1; j++)
            if(arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
    puts(arr);
}
int main()
{
    char string[120] = {'\0'}, sieve[120] = {'\0'};
    fgets(string, 120, stdin);

    int length = lengthGet(string);
    string[length] = '\0';

    for(int i = 0, j = 0; i < length; i++)
    {
        if(string[i] == '*')
            continue;
        sieve[j] = string[i];
        j++;
    }
    bubbleSort(sieve, lengthGet(sieve));
    return 0;
}