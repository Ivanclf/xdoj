#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, array[1010] = {0}, sieve[1010][2] = {0};
    int max = -1, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i] == sieve[j][0])
            {
                sieve[j][1]++;
                break;
            }
            else if (!sieve[j][0])
            {
                sieve[j][0] = array[i];
                sieve[j][1]++;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(max < sieve[i][1])
        {
            max = sieve[i][1];
            temp = sieve[i][0];
        }
    }
    printf("%d", temp);
    return 0;
}