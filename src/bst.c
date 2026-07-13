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
    {
        insertBSTNode(&((*root)->left), book);
    }
    else
    {
        insertBSTNode(&((*root)->right), book);
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
