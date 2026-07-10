#include <stdio.h>
#include "../include/utils.h"

void menu()
{
    printf("\n=========================================\n");
    printf("      LIBRARY MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Nhap danh sach sach\n");
    printf("2. Them sach\n");
    printf("3. Hien thi danh sach\n");
    printf("4. Tim kiem sach\n");
    printf("5. Xoa sach\n");
    printf("6. Cap nhat thong tin sach\n");
    printf("7. Sap xep danh sach\n");
    printf("8. Thong ke\n");
    printf("9. Doc du lieu tu file\n");
    printf("10. Ghi du lieu vao file\n");
    printf("11. Stack (Undo)\n");
    printf("12. Queue\n");
    printf("13. BST\n");
    printf("0. Thoat\n");
    printf("=========================================\n");
}

void clearInputBuffer()
{
    while (getchar() != '\n');
}

void pauseScreen()
{
    printf("\nNhan Enter de tiep tuc...");
    getchar();
}