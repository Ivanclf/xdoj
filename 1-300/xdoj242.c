// 242和242plus有一个是AC的
// 请注意是哪一个
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student student;
struct Student
{
    int identification;
    char name[15];
    double avgScore;
    student *next;
};
student *addNode(int identification, char name[], double avgScore, student *head)
{
    student *toStudent = (student *)malloc(sizeof(student));
    toStudent->identification = identification;
    strcpy(toStudent->name, name);
    toStudent->avgScore = avgScore;
    toStudent->next = head;
    return toStudent;
}
void swopNode(student *oneNode, student *twoNode)
{
    oneNode->next = oneNode->next->next;
    twoNode->next = twoNode->next->next;
    oneNode->next->next = twoNode;
}
student *findNode(student *head, int n)
{
    for (int i = 0; i < n; i++)
        head = head->next;
    return head;
}
int main()
{
    int identification, chiScore, mathScore, engScore, n;
    double avgScore;
    char name[15] = {'\0'};
    student *head = NULL, *temp = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d %d %d", &identification, &name, &chiScore, &mathScore, &engScore);
        avgScore = (chiScore + mathScore + engScore) / 3.0;
        head = addNode(identification, name, avgScore, head);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (!j && head->avgScore - head->next->avgScore < 0)
            {
                temp = head->next;
                head->next = head->next->next;
                temp->next = head;
                head = temp;
            }
            else if (findNode(head, j - 1)->next->avgScore - findNode(head, j)->next->avgScore < 0)
                swopNode(findNode(head, j - 1), findNode(head, j));
        }
    }
    for(student *print = head; print != NULL; print = print->next)
        printf("%d %s %.1lf\n", print->identification, print->name, print->avgScore);
    free(head);
    return 0;
}