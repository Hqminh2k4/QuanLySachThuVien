#ifndef BOOK_H
#define BOOK_H

#define MAX_ID 6
#define MAX_NAME 30
#define MAX_AUTHOR 25
#define MAX_CATEGORY 20
#define MAX_PUBLISHER 30

typedef struct Book
{
    char maSach[MAX_ID];            // Mã sách tối đa 6 ký tự
    char tenSach[MAX_NAME];         // Tên sách tối đa 30 ký tự
    char tacGia[MAX_AUTHOR];        // Tác giả tối đa 25 ký tự
    char theLoai[MAX_CATEGORY];     // Thể loại tối đa 20 ký tự
    char nhaXuatBan[MAX_PUBLISHER]; // Nhà xuất bản tối đa 30 ký tự

    int namXuatBan; // Năm xuất bản
    float gia;      // Giá trị sách
    int soLuong;    // Số lượng sách hiện có

} Book;

#endif