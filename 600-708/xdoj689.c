#include <stdio.h>
#include <stdlib.h>
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
int main()
{
    int counter, result = 0;;
    char originArray[55] = {'\0'};
    char certianArray[5] = {'\0'};
    fgets(certianArray, 5, stdin);
    fgets(originArray, 55, stdin);
    int lengthofOrigin = lengthGet(originArray);
    int lengthofCertian = lengthGet(certianArray);
    originArray[lengthofOrigin] = '\0';
    certianArray[lengthofCertian] = '\0';

    for(int i = 0; i <= lengthofOrigin - lengthofCertian; i++)
    {
        counter = 0;
        for(int j = 0; j < lengthofCertian; j++)
        {
            if(certianArray[j] != originArray[i + j])
                break;
            counter++;
            if(counter == lengthofCertian)
            {
                result++;
                break;
            }
        }
    }
    printf("%d", result);
    return 0;

}