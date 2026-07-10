#ifndef BOOK_H
#define BOOK_H

#define MAX_ID 20
#define MAX_NAME 100
#define MAX_AUTHOR 100
#define MAX_CATEGORY 50
#define MAX_PUBLISHER 100

typedef struct
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