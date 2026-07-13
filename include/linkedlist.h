#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "book.h"

typedef struct Node
{
    Book data;
    struct Node *next;
} Node;

// Tạo node mới
Node *createNode(Book book);

// Thêm sách
void addFirst(Node **head, Book book);
void addLast(Node **head, Book book);

// Hiển thị
void displayBooks(Node *head);

// Tìm kiếm
Node *findBookById(Node *head, char maSach[]);
Node *findBookByName(Node *head, char tenSach[]);

// Xóa
int deleteBook(Node **head, char maSach[]);

// Cập nhật
int updateBook(Node *head, char maSach[]);

// Kiểm tra trùng mã
int isDuplicateId(Node *head, char maSach[]);

// Giải phóng bộ nhớ
void freeList(Node **head);

Book inputBook(Node *head);

#endif