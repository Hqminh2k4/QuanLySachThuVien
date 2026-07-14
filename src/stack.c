#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

// Khởi tạo Stack
void initStack(Stack *s)
{
    s->top = NULL;
}

// Kiểm tra Stack rỗng
int isStackEmpty(Stack *s)
{
    return s->top == NULL;
}

// Push
void push(Stack *s, UndoData data)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));

    if (newNode == NULL)
    {
        printf("Khong du bo nho!\n");
        return;
    }

    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop
UndoData pop(Stack *s)
{
    UndoData emptyData;
    memset(&emptyData, 0, sizeof(UndoData));

    if (isStackEmpty(s))
    {
        printf("Stack rong!\n");
        return emptyData;
    }

    StackNode *temp = s->top;
    UndoData data = temp->data;

    s->top = temp->next;

    free(temp);

    return data;
}

// Peek
UndoData peek(Stack *s)
{
    UndoData emptyData;
    memset(&emptyData, 0, sizeof(UndoData));

    if (isStackEmpty(s))
    {
        return emptyData;
    }

    return s->top->data;
}

// Giải phóng Stack
void freeStack(Stack *s)
{
    while (!isStackEmpty(s))
    {
        pop(s);
    }
}