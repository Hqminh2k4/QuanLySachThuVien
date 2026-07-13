#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bst.h"
//============ TAO NODE BST ============
BSTNode *createBSTNode(Book book)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));

    if (newNode == NULL)
    {
        printf("Khong du bo nho!\n");
        return NULL;
    }

    newNode->data = book;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}