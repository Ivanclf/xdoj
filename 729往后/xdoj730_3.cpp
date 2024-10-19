#include <iostream>
#include <malloc.h>

typedef struct Poly
{
    int number;
    int index;
    struct Poly *next;
} poly, *poly_pointer;

poly_pointer insert_to_head(poly_pointer head, int number, int index)
{
    poly_pointer to_node = (poly_pointer)malloc(sizeof(poly));
    to_node->number = number;
    to_node->index = index;
    to_node->next = head;
    return to_node;
}
poly_pointer insert_to_foot(poly_pointer head, int number, int index)
{
    poly_pointer to_node = (poly_pointer)malloc(sizeof(poly));
    to_node->number = number;
    to_node->index = index;
    head->next = to_node;
    return to_node;
}
poly_pointer del(poly_pointer target)
{
    poly_pointer to_node;
    if (target->next)
    {
        to_node = target->next;
        free(target);
        return to_node;
    }
    else
    {
        free(target);
        return NULL;
    }
}
int main()
{
    poly_pointer first_number = NULL, second_number = NULL, result = NULL, opr = NULL;
    int n, m, t, temp_number, temp_index;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_number >> temp_index;
        first_number = insert_to_head(first_number, temp_number, temp_index);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp_number >> temp_index;
        second_number = insert_to_head(second_number, temp_number, temp_index);
    }
    while (first_number && second_number)
    {
        if (first_number->index < second_number->index)
        {
            result = insert_to_foot(result, first_number->number, first_number->index);
            first_number = del(first_number);
        }
        else if (first_number->index > second_number->index)
        {
            if (t)
            {
                result = insert_to_foot(result, 0 - second_number->number, second_number->index);
                second_number = del(second_number);
            }
            else
            {
                result = insert_to_foot(result, second_number->number, second_number->index);
                second_number = del(second_number);
            }
        }
        else
        {
            if(t)
            {
                result = insert_to_foot(result, first_number->number = second_number->number, first_number->index);
                first_number = del(first_number);
                second_number = del(second_number);
            }
            else
            {
                result = insert_to_foot(result, first_number->number + second_number->number, first_number->index);
                first_number = del(first_number);
                second_number = del(second_number);
            }
        }
    }
    while (first_number)
    {
        result = insert_to_foot(result, first_number->number, first_number->index);
        first_number = del(first_number);
    }
    while (second_number)
    {
        if(t)
        {
            result = insert_to_foot(result, 0 - second_number->number, second_number->index);
            second_number = del(second_number);
        }
        else
        {
            result = insert_to_foot(result, second_number->number, second_number->index);
            second_number = del(second_number);
        }
    }
    cout << (n > m ? n : m) << " ";
    while (result)
    {
        cout << result->number << " " << result->index << " ";
        result = del(result);
    }
    cout << endl;
    return 0;
}