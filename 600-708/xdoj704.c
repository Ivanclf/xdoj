#include <stdio.h>
int main()
{
    int rsl = 0, n = 0;
    char a[51] = {'\0'};
    fgets(a, 50, stdin);
    for (int i = 0; a[i] != '\n' && a[i] != ' ' && a[i] != '\0'; i++)
    {
        switch (a[i])
        {
        case '0':
            n++;
            break;
        case '1':
            rsl += 1;
            break;
        case '2':
            rsl += 2;
            break;
        case '3':
            rsl += 3;
            break;
        case '4':
            rsl += 4;
            break;
        case '5':
            rsl += 5;
            break;
        case '6':
            rsl += 6;
            break;
        case '7':
            rsl += 7;
            break;
        case '8':
            rsl += 8;
            break;
        case '9':
            rsl += 9;
            break;
        case 'A':
        case 'a':
            rsl += 10;
            break;
        case 'B':
        case 'b':
            rsl += 11;
            break;
        case 'C':
        case 'c':
            rsl += 12;
            break;
        case 'D':
        case 'd':
            rsl += 13;
            break;
        case 'E':
        case 'e':
            rsl += 14;
            break;
        case 'F':
        case 'f':
            rsl += 15;
            break;
        default:
            continue;
        }
    }
    if (rsl || n)
        printf("%d", rsl);
    else
        printf("NO");
    return 0;
}