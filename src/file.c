#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "file.h"
#include "utils.h"

#define FILE_PATH "data/library.txt"

void loadList(Node **head)
{
    FILE *file = fopen(FILE_PATH, "r+");
    if (file == NULL)
    {
        printf(RED_TEXT "Khong the mo file de doc du lieu: %s ! \n" RESET, strerror(errno));
        return;
    }

    Book book;
    while (fscanf(file, "%19[^\n|]|%99[^\n|]|%99[^\n|]|%49[^\n|]|%99[^\n|]|%d|%f|%d\n",
                  book.maSach, book.tenSach, book.tacGia, book.theLoai,
                  book.nhaXuatBan, &book.namXuatBan, &book.gia, &book.soLuong) == 8)
    {
        addLast(head, book);
    }

    fclose(file);
}

void saveList(Node *head)
{
    FILE *file = fopen(FILE_PATH, "w");
    if (file == NULL)
    {
        printf(RED_TEXT "Khong the mo file de luu du lieu: %s ! \n" RESET, strerror(errno));
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        fprintf(file, "%s|%s|%s|%s|%s|%d|%.0f|%d\n",
                temp->data.maSach, temp->data.tenSach, temp->data.tacGia,
                temp->data.theLoai, temp->data.nhaXuatBan, temp->data.namXuatBan,
                temp->data.gia, temp->data.soLuong);
        temp = temp->next;
    }

    fclose(file);
}