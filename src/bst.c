#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

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

void insertBSTNode(BSTRoot *root, Book book)
{
    if (*root == NULL)
    {
        *root = createBSTNode(book);
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
        *root = createBSTNode(book);
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

//============ DUYET INORDER ============
void inorder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    printf("%-6s %-25s %-25s %-20s %-25s %6d %10.0f %4d\n",
           root->data.maSach,
           root->data.tenSach,
           root->data.tacGia,
           root->data.theLoai,
           root->data.nhaXuatBan,
           root->data.namXuatBan,
           root->data.gia,
           root->data.soLuong);

    inorder(root->right);
}
//Duyệt postorder
void postorder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    printf("%-6s %-25s %-25s %-20s %-25s %6d %10.0f %4d\n",
           root->data.maSach,
           root->data.tenSach,
           root->data.tacGia,
           root->data.theLoai,
           root->data.nhaXuatBan,
           root->data.namXuatBan,
           root->data.gia,
           root->data.soLuong);
}

Node *findBookByIdBST(BSTNode *root, char maSach[])
{
    if (root == NULL)
    {
        return NULL;
    }

    int cmp = strcmp(maSach, root->data.maSach);

    if (cmp == 0)
    {
        return createNode(root->data);
    }

    if (cmp < 0)
    {
        return findBookByIdBST(root->left, maSach);
    }

    return findBookByIdBST(root->right, maSach);
}

