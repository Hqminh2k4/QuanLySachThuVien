#ifndef BST_H
#define BST_H

#include "book.h"
#include "linkedlist.h"

typedef struct BSTNode
{
    Book data;
    struct BSTNode *left;
    struct BSTNode *right;

} BSTNode;

// Tao node BST
BSTNode *createBSTNode(Book book);

// Them mot sach vao BST
void insertBST(BSTNode **root, Book book);

// Tao BST tu danh sach lien ket
void buildBSTFromList(BSTNode **root, Node *head);

// Duyet Inorder
void inorder(BSTNode *root);

// Tim sach theo ma
BSTNode *searchBookByIdBST(BSTNode *root, char maSach[]);

#endif