#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

void insertBSTNode(BSTRoot *root, Book book)
{
    if (*root == NULL)
    {
        *root = (BSTNode *)malloc(sizeof(BSTNode));
        (*root)->data = book;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp(book.maSach, (*root)->data.maSach) < 0)
        insertBSTNode(&((*root)->left), book);
    else
        insertBSTNode(&((*root)->right), book);
}

void insertBSTNodeForName(BSTRoot *root, Book book)
{
    if (*root == NULL)
    {
        *root = (BSTNode *)malloc(sizeof(BSTNode));
        (*root)->data = book;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp(book.tenSach, (*root)->data.tenSach) < 0)
    {
        insertBSTNodeForName(&((*root)->left), book);
    }
    else
    {
        insertBSTNodeForName(&((*root)->right), book);
    }
}

void insertBSTNodeFromLinkedList(BSTRoot *root, Node *head)
{
    while (head != NULL)
    {
        insertBSTNode(root, head->data);
        head = head->next;
    }
}

void insertBSTNodeForNameFromLinkedList(BSTRoot *root, Node *head)
{
    while (head != NULL)
    {
        insertBSTNodeForName(root, head->data);
        head = head->next;
    }
}

Node *browsePreorder(BSTRoot root)
{
    static Node *result = NULL;
    if (root != NULL)
    {
        addLast(&result, root->data);
        browsePreorder(root->left);
        browsePreorder(root->right);
    }

    return result;
}

Node *searchByBookName(BSTRoot root, const char *tenSach)
{
    if (root != NULL)
    {
        int comparison = strcasecmp(root->data.tenSach, tenSach);
        if (comparison == 0)
            return createNode(root->data);
        else if (comparison > 0)
            return searchByBookName(root->left, tenSach);

        return searchByBookName(root->right, tenSach);
    }

    return NULL;
}
