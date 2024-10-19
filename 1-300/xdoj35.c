#include<stdio.h>
#include<math.h>


void pList(int a[])
{
    int counter = 2, j = 2;
    for(int i = 3; i < 1050; i++)
    {
        for(j = 2; j <= i / 2; j++)
        {
            if(!(i % j))
                break;
        if(j == i / 2)
        {
            a[counter] = i;
            counter++;
        }
        }
    }
}

int main()
{
    int a[500] ={2, 3, 0};
    int min = 10000, max = 0;
    int evenNumber = 0;
    scanf("%d", &evenNumber);
    pList(a);

    for(int i = 0; a[i]; i++)
    {
        for(int j = i + 1; a[j]; j++)
        {
            if(a[i] + a[j] == evenNumber)
            {
                printf("%d %d", a[i], a[j]);
                return 0;
            }
        }
    }
}