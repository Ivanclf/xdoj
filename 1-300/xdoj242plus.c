// 242和242plus有一个是AC的
// 请注意是哪一个
#include<stdio.h>
typedef struct Student
{
    int id;
    float avgScore;
    char name[15];
}student;
int main()
{
    student a[101], temp;
    int n;
    float score1, score2, score3;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %s %f %f %f", &a[i].id, &a[i].name, &score1, &score2, &score3);
        a[i].avgScore = (score1 + score2 + score3) / 3.0;
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j].avgScore < a[j + 1].avgScore)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d %s %.1f\n", a[i].id, a[i].name, a[i].avgScore);
    return 0;
}