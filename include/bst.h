#ifndef BST_H
#define BST_H

#include "book.h"
#include "linkedlist.h"

typedef struct BSTNode
{
    Book data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode, *BSTRoot;

void insertBSTNode(BSTRoot *root, Book book);
void insertBSTNodeFromLinkedList(BSTRoot *root, Node *head);
void balanceBST(BSTRoot *root);
Node *browsePreorder(BSTRoot root);
Node *searchByBookName(BSTRoot root, const char *tenSach);

#endif
