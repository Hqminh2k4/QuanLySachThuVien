#ifndef QUEUE_H
#define QUEUE_H

#include <linkedlist.h>

typedef struct Queue
{
    Node *front; // Trỏ đến phần tử đầu tiên
    Node *rear; // Trỏ đến phần tử cuối cùng
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, Node *node);
Node *dequeue(Queue *q);

#endif
