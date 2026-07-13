#ifndef BOOK_H
#define BOOK_H

#define MAX_ID 6
#define MAX_NAME 30
#define MAX_AUTHOR 25
#define MAX_CATEGORY 20
#define MAX_PUBLISHER 30

typedef struct Book
{
    char maSach[MAX_ID];
    char tenSach[MAX_NAME];
    char tacGia[MAX_AUTHOR];
    char theLoai[MAX_CATEGORY];
    char nhaXuatBan[MAX_PUBLISHER];

    int namXuatBan;
    float gia;
    int soLuong;

} Book;

#endif