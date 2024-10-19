#include <iostream>
#include <malloc.h>
typedef struct Person
{
    int order;
    int password;
    struct Person *next;
} person;
person output, *head = NULL;
person *insert(person *p, int order, int password)
{
    person *to_node = (person *)malloc(sizeof(person));
    to_node->order = order;
    to_node->password = password;
    if (!p)
        head = to_node;
    else
        p->next = to_node;
    return to_node;
}

person *del(person *target)
{
    person *before_target;
    if (target->next && target->next != target)
    {
        output.order = target->order;
        output.password = target->password;
        for (before_target = target->next; before_target->next != target; before_target = before_target->next)
            ;
        before_target->next = target->next;
        free(target);
        return before_target->next;
    }
    else
    {
        output.order = target->order;
        output.password = target->password;
        free(target);
        return NULL;
    }
}

int main()
{
    int n, m, c;
    std::cin >> n >> m;
    person *opr = NULL;
    for (int i = 0; i < n; i++)
    {
        std::cin >> c;
        opr = insert(opr, i + 1, c);
    }
    opr->next = head;
    while (head && head->next)
    {
        for (int i = 0; i < m - 1; i++)
            head = head->next;
        head = del(head);
        std::cout << output.order << " ";
        m = output.password;
    }
    std::cout << std::endl;
    return 0;
}