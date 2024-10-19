#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
typedef struct
{
    int *data; // 队列空间首地址
    int maxSize;
    // 队列空间的大小
    int rear;
    int length;
} Queue;


// 尾指针，队列不空时指示队尾元素之后的位置
// 队列中的元素个数
int createQueue(Queue *q, int n); // 创建容量为 n 的空队列
int isEmpty(Queue q);
// 判断队列是否为空，若为空则返回1，否则返回0
void output(Queue q);
// 输出队列中从队头至队尾的所有元素，不修改队列
int in(Queue *q, int e); // 元素 e 入队列，成功时返回 OK，失败则返回ERROR
// （队满时入队失败，队列空间不扩充）
int out(Queue *q, int *e);
// 非空时队头元素出队（通过参数e返回队头元素）
// 若出队成功则返回OK，否则返回ERROR


int main()
{
    Queue Q;
    int n;
    scanf("%d", &n);
    if (createQueue(&Q, n) != OK)
        return 0;
    int elem;
    while (1)
    {
        scanf("%d", &elem);
        if (0 == elem)
            break;
        if (in(&Q, elem) != OK)
        {
            printf("OverFlow\n");
            break;
        }
    }
    output(Q);
    int c = 4;
    while (c--)
    {
        if (out(&Q, &elem))
        {
            printf("%d ", elem);
        }
        else
        {
            printf("UnderFlow\n");
            break;
        }
    }
    return 0;
} // main

int createQueue(Queue *q, int n)
{
    q->data = (int *)malloc(n * sizeof(int)); // 申请队列空间
    if (!q->data)
        return ERROR;
    q->length = 0;
    q->rear = 0;
    q->maxSize = n;
    return OK;
}

int isEmpty(Queue q) { return (0 == q.length); }
void output(Queue q)
{
    if (isEmpty(q))
    {
        return;
    }
    int idx = (q.rear - q.length + q.maxSize) % q.maxSize;
    do
    {
        printf("%d ", q.data[idx]);
        idx = (idx + 1) % q.maxSize;
    } while (idx != q.rear);
}
int in(Queue *q, int e)// 元素 e 入队列，成功时返回 OK，失败则返回ERROR
{
    if(q->maxSize == q->length)
        return ERROR;
    q->data[q->rear] = e;
    q->length++, q->rear = (++q->rear) % q->maxSize;
    return OK;
}
// （队满时入队失败，队列空间不扩充）
int out(Queue *q, int *e)
{
    if(!q->length)
        return ERROR;
    *e = q->data[0];
    q->data = ++q->data;
    q->length--;
    return OK;
}
// 非空时队头元素出队（通过参数e返回队头元素）
// 若出队成功则返回OK，否则返回ERROR