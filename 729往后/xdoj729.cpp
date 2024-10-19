#include <stdio.h>
#include<malloc.h>
typedef struct Person
{
    int order;
    int password;
    struct Person *next;
} person;
int global_order;
int global_password;
person *head = NULL;
person *insert(person *head, int order, int password)
{
    person *to_node = (person *)malloc(sizeof(person));
    to_node->order = order;
    to_node->password = password;
    head->next = to_node;
    return to_node;
}

person *del(person *target)
{
    person *before_target;
    if(target->next && target->next != target)
    {
        global_order = target->order;
        global_password = target->password;
        for(before_target = target->next; before_target->next != target; before_target = before_target->next);
        before_target->next = target->next;
        free(target);
        return before_target->next;
    }
    else
    {
        global_order = target->order;
        global_password = target->password;
        free(target);
        return NULL;
    }
}

int main()
{
    int n, m, c;
    scanf("%d %d", &n, &m);
    person *temp = (person *)malloc(sizeof(person));
    person *top = temp;
    for (int i = 0; i < n; i++)
    {
        if (!i)
        {
            scanf("%d", &temp->password);
            temp->order = 1;
            temp->next = head;
            head = temp;
        }
        else
        {
            scanf("%d", &c);
            head = insert(head, i + 1, c);
        }
    }
    head->next = temp;
    head = head->next;
    while (head && head->next)
    {
        for (int i = 0; i < m - 1; i++)
            head = head->next;
        head = del(head);
        printf("%d ", global_order);
        m = global_password;
    }
    return 0;
}