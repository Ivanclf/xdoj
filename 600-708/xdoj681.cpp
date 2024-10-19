#include<iostream>
int main()
{
    int signal[40] = {0};
    int n, counter = 0;
    scanf("%d ", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &signal[i]);
    for(int i = 0; i < n - 2; i++)
        if(signal[i] == 3 && signal[i + 1] == 5 && signal[i + 2] == 7)
            counter++;
    printf("%d\n", counter);
    return 0;
}