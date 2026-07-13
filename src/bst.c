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
//============ THEM NODE VAO BST ============
void insertBST(BSTNode **root, Book book)
{
    if (*root == NULL)
    {
        *root = createBSTNode(book);
        return;
    }

    if (strcmp(book.maSach, (*root)->data.maSach) < 0)
    {
        insertBST(&(*root)->left, book);
    }
    else if (strcmp(book.maSach, (*root)->data.maSach) > 0)
    {
        insertBST(&(*root)->right, book);
    }
}
//============ TAO BST TU DANH SACH LIEN KET ============
void buildBSTFromList(BSTNode **root, Node *head)
{
    *root = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        insertBST(root, temp->data);
        temp = temp->next;
    }
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
//============ HIEN THI 1 SACH BST ============
void displayBookBST(BSTNode *book)
{
    printf("%-6s %-25s %-25s %-20s %-25s %-6s %-10s %-4s\n",
           "Ma",
           "Ten sach",
           "Tac gia",
           "The loai",
           "Nha XB",
           "Nam",
           "Gia",
           "SL");

    printf("---------------------------------------------------------------------------------------------------------------\n");

    printf("%-6s %-25s %-25s %-20s %-25s %6d %10.0f %4d\n",
           book->data.maSach,
           book->data.tenSach,
           book->data.tacGia,
           book->data.theLoai,
           book->data.nhaXuatBan,
           book->data.namXuatBan,
           book->data.gia,
           book->data.soLuong);
}