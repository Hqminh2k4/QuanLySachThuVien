#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"
#include "linkedlist.h"
#include "utils.h"

Node *createNode(Book book)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Khong du bo nho!\n");
        return NULL;
    }

    newNode->data = book;
    newNode->next = NULL;

    return newNode;
}

void addFirst(Node **head, Book book)
{
    Node *newNode = createNode(book);

    if (newNode == NULL)
        return;

    newNode->next = *head;

    *head = newNode;
}

void addLast(Node **head, Book book)
{
    Node *newNode = createNode(book);

    if (newNode == NULL)
        return;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void displayBooks(Node *head)
{
    if (head == NULL)
    {
        printf(YELLOW_TEXT "Danh sach rong!\n" RESET);
        return;
    }

    printf("%-6s %-30s %-25s %-20s %-30s %6s %10s %4s\n", "Ma", "Ten sach", "Tac gia", "The loai", "Nha XB", "Nam XB", "Gia", "SL");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    Node *temp = head;

    while (temp != NULL)
    {
        printf("%-6s %-30s %-25s %-20s %-30s %6d %10.0f %4d\n",
               temp->data.maSach, temp->data.tenSach, temp->data.tacGia, temp->data.theLoai,
               temp->data.nhaXuatBan, temp->data.namXuatBan, temp->data.gia, temp->data.soLuong);
        temp = temp->next;
    }
}

void displayBook(Book book)
{
    printf("%-6s %-30s %-25s %-20s %-30s %6s %10s %4s\n",
           "Ma", "Ten sach", "Tac gia", "The loai", "Nha XB", "Nam XB", "Gia", "SL");

    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("%-6s %-30s %-25s %-20s %-30s %6d %10.0f %4d\n",
           book.maSach,
           book.tenSach,
           book.tacGia,
           book.theLoai,
           book.nhaXuatBan,
           book.namXuatBan,
           book.gia,
           book.soLuong);
}
//Tìm kiếm theo mã sách
Node *findBookById(Node *head, char maSach[])
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->data.maSach, maSach) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

Node *findBookByName(Node *head, char tenSach[])
{
    Node *temp = head;
    Node *result = NULL;

    stringToLower(tenSach);

    while (temp != NULL)
    {
        char *tenSachLower = strdup(temp->data.tenSach);
        stringToLower(tenSachLower);
        if (strstr(tenSachLower, tenSach) != NULL)
        {
            addLast(&result, temp->data);
        }

        temp = temp->next;
    }

    return result;
}

int isDuplicateId(Node *head, char maSach[])
{
    return findBookById(head, maSach) != NULL;
}

void freeList(Node **head)
{
    Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

Book inputBook(Node *head)
{
    Book book;

    do
    {
        printf("Nhap ma sach: ");
        scanf("%6s", book.maSach);

        if (isDuplicateId(head, book.maSach))
        {
            printf("Ma sach da ton tai! Vui long nhap lai.\n");
        }

    } while (isDuplicateId(head, book.maSach));

    clearInputBuffer();

    printf("Nhap ten sach: ");
    fgets(book.tenSach, sizeof(book.tenSach), stdin);
    book.tenSach[strcspn(book.tenSach, "\n")] = '\0';

    printf("Nhap tac gia: ");
    fgets(book.tacGia, sizeof(book.tacGia), stdin);
    book.tacGia[strcspn(book.tacGia, "\n")] = '\0';

    printf("Nhap the loai: ");
    fgets(book.theLoai, sizeof(book.theLoai), stdin);
    book.theLoai[strcspn(book.theLoai, "\n")] = '\0';

    printf("Nhap nha xuat ban: ");
    fgets(book.nhaXuatBan, sizeof(book.nhaXuatBan), stdin);
    book.nhaXuatBan[strcspn(book.nhaXuatBan, "\n")] = '\0';

    printf("Nhap nam xuat ban: ");
    scanf("%d", &book.namXuatBan);

    printf("Nhap gia sach: ");
    scanf("%f", &book.gia);

    printf("Nhap so luong: ");
    scanf("%d", &book.soLuong);

    return book;
}
//============== chuc nang xoa sach ==============
int deleteBook(Node **head, char maSach[])
{
    if (*head == NULL)
    {
        return 0;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->data.maSach, maSach) == 0)
        {
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            return 1;
        }

        prev = temp;
        temp = temp->next;
    }

    return 0;
}
//============== chuc nang cap cap nhat ==============
int updateBook(Node *head, char maSach[])
{
    Node *book = findBookById(head, maSach);

    if (book == NULL)
    {
        return 0;
    }

    getchar();

    printf("Nhap ten sach moi: ");
    fgets(book->data.tenSach, MAX_NAME, stdin);
    book->data.tenSach[strcspn(book->data.tenSach, "\n")] = '\0';

    printf("Nhap tac gia moi: ");
    fgets(book->data.tacGia, MAX_AUTHOR, stdin);
    book->data.tacGia[strcspn(book->data.tacGia, "\n")] = '\0';

    printf("Nhap the loai moi: ");
    fgets(book->data.theLoai, MAX_CATEGORY, stdin);
    book->data.theLoai[strcspn(book->data.theLoai, "\n")] = '\0';

    printf("Nhap nha xuat ban moi: ");
    fgets(book->data.nhaXuatBan, MAX_PUBLISHER, stdin);
    book->data.nhaXuatBan[strcspn(book->data.nhaXuatBan, "\n")] = '\0';

    printf("Nhap nam xuat ban moi: ");
    scanf("%d", &book->data.namXuatBan);

    printf("Nhap gia moi: ");
    scanf("%f", &book->data.gia);

    printf("Nhap so luong moi: ");
    scanf("%d", &book->data.soLuong);

    return 1;
}

void sortBooksById(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node *current, *next_node;
    Book temp_book;

    for (current = *head; current != NULL; current = current->next)
    {
        for (next_node = current->next; next_node != NULL; next_node = next_node->next)
        {
            if (strcmp(current->data.maSach, next_node->data.maSach) > 0)
            {
                temp_book = current->data;
                current->data = next_node->data;
                next_node->data = temp_book;
            }
        }
    }
}
//Sắp xếp theo tên sách 
void sortBooksByName(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node *current, *next_node;
    Book temp_book;

    for (current = *head; current != NULL; current = current->next)
    {
        for (next_node = current->next; next_node != NULL; next_node = next_node->next)
        {
            if (strcmp(current->data.tenSach, next_node->data.tenSach) > 0)
            {
                temp_book = current->data;
                current->data = next_node->data;
                next_node->data = temp_book;
            }
        }
    }
}
// Tong gia tri của tat ca sach
float totalBookValue(Node *head)
{
    float totalValue = 0.0f;
    Node *temp = head;

    while (temp != NULL)
    {
        totalValue += temp->data.gia * temp->data.soLuong;
        temp = temp->next;
    }

    return totalValue;
}
//Thống kê số lượng sách theo thể loại
void statisticByCategory(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }

    int giaoTrinh = 0;
    int thamKhao = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->data.theLoai, "Giao trinh") == 0)
        {
            giaoTrinh++;
        }
        else if (strcmp(temp->data.theLoai, "Tham khao") == 0)
        {
            thamKhao++;
        }

        temp = temp->next;
    }

    printf("\n%-20s %5d sach\n", "Giao trinh:", giaoTrinh);
    printf("%-20s %5d sach\n", "Tham khao:", thamKhao);
}
//Undo
void replaceBook(Node *head, Book book)
{
    Node *temp = findBookById(head, book.maSach);

    if (temp != NULL)
    {
        temp->data = book;
    }
}
//Lấy vị trí sách để Undo
int getBookPosition(Node *head, char maSach[])
{
    int pos = 0;

    while (head != NULL)
    {
        if (strcmp(head->data.maSach, maSach) == 0)
            return pos;

        pos++;
        head = head->next;
    }

    return -1;
}
void insertAtPosition(Node **head, Book book, int position)
{
    if (position <= 0 || *head == NULL)
    {
        addFirst(head, book);
        return;
    }

    Node *newNode = createNode(book);

    Node *temp = *head;

    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}