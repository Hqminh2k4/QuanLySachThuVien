#ifndef BST_H
#define BST_H

#include "book.h"
#include "linkedlist.h"

typedef struct BSTNode
{
    Book data;              // Dữ liệu sách
    struct BSTNode *left;   // Trỏ đến phần tử con bên trái
    struct BSTNode *right;  // Trỏ đến phần tử con bên phải
} BSTNode, *BSTRoot;

// Tao node BST
BSTNode *createBSTNode(Book book);
void insertBSTNode(BSTRoot *root, Book book);
void insertBSTNodeForName(BSTRoot *root, Book book);
void insertBSTNodeFromLinkedList(BSTRoot *root, Node *head);
void insertBSTNodeForNameFromLinkedList(BSTRoot *root, Node *head);
void balanceBST(BSTRoot *root);
Node *browsePreorder(BSTRoot root);
Node *searchByBookName(BSTRoot root, const char *tenSach);

// Duyet Inorder
void inorder(BSTNode *root);
// Duyet Postorder
void postorder(BSTNode *root);

// TIM KIEM 
Node *findBookByIdBST(BSTNode *root, char maSach[]);

#endif
