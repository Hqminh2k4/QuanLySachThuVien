#include <stdio.h>

#include "queue.h"
#include <utils.h>

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, Node *node)
{
    if (isEmpty(q))
    {
        q->front = q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}

Node *dequeue(Queue *q)
{
    Node *temp = q->front;
    if (temp != NULL)
    {
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
    }
    return temp;
}
