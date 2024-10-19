#include <stdio.h>
int main()
{
    int temp = 0, trend;
    char inputString[1000] = {'\0'};
    char outputString[50][25] = {'\0'};
    fgets(inputString, 1000, stdin);
    for (int i = 0; inputString[i]; i++)
    {
        if (inputString[i] >= '0' && inputString[i] <= '9')
        {
            for (int j = 0;; j++)
            {
                outputString[temp][j] = inputString[i];
                if (inputString[i + 1] < '0' || inputString[i + 1] > '9')
                {
                    temp++;
                    break;
                }
                i++;
            }
        }
    }
    for (temp = 0; outputString[temp][0]; temp++)
    {
        for (int i = 0; outputString[temp][i + 1]; i++)
        {
            if (!i)
            {
                if (outputString[temp][1] - outputString[temp][0] == 1)
                    trend = 1;
                else if (outputString[temp][1] - outputString[temp][0] == -1)
                    trend = -1;
                else
                {
                    outputString[temp][0] = '\0';
                    break;
                }
            }
            else if (outputString[temp][i + 1] - outputString[temp][i] != trend)
            {
                outputString[temp][0] = '\0';
                break;
            }
        }
    }
    for (temp = 0; temp < 50; temp++)
    {
        if (outputString[temp][0] == '\0')
            continue;
        else
        {
            for (int i = 0; outputString[temp][i]; i++)
                printf("%c", outputString[temp][i]);
            printf("\n");
        }
    }
    return 0;
}