#include <stdio.h>

#include "utils.h"

const char *functions[] = {
    "Them 1 Sach vao cuoi",
    "Hien thi danh sach Sach",
    "Sua thong tin 1 Sach",
    "Xoa 1 Sach",
    "Sap xep theo Ten Sach (BST Inorder)",
    "Tim kiem theo Ma Sach (BST)",

    "Undo (Stack)",

    "Tim kiem (Linked List)...",
    "Chuc nang hang doi (Queue)...",
    "Duyet danh sach (BST)...",
    "Thong ke...",

    "Xem lich su thao tac",
};

void menu()
{
    printf(
        "\n=========================================\n"
        "      HE THONG QUAN LY SACH THU VIEN      \n"
        "=========================================\n");

    for (int i = 0; i < 12; i++)
    {
        printf("%d. %s\n", i + 1, functions[i]);
    }

    printf(
        "0. Thoat\n"
        "=========================================\n");
}

void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}

void pauseScreen()
{
    printf("\nNhan Enter de tiep tuc...");
    getchar();

    clearScreen();
}

void clearScreen()
{
    // \e[1;1H di chuyen con tro ve vi tri (1,1)
    // \e[2J xoa toan bo man hinh
    printf("\e[1;1H\e[2J");
}