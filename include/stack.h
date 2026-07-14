#ifndef STACK_H
#define STACK_H

#include "book.h"

#define ACTION_ADD 1
#define ACTION_DELETE 2
#define ACTION_UPDATE 3

typedef struct UndoData
{
    int action;
    Book book;
    int position;      // vị trí trong Linked List
} UndoData;

typedef struct StackNode
{
    UndoData data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

// Khoi tao
void initStack(Stack *s);

// Rong?
int isStackEmpty(Stack *s);

// Push
void push(Stack *s, UndoData data);

// Pop
UndoData pop(Stack *s);

// Peek
UndoData peek(Stack *s);

// Giai phong
void freeStack(Stack *s);

#endif