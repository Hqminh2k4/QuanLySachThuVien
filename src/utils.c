#include <stdio.h>
#include <string.h>

#include "utils.h"

const static char *functions[] = {
    // Co ban
    "Them 1 Sach vao cuoi",    // Minh
    "Hien thi danh sach Sach", // Tu
    "Sua thong tin 1 Sach",    // Duy
    "Xoa 1 Sach",              // Duy

    "Tim kiem theo Ma Sach (Linked List)",  // Minh
    "Tim kiem theo Ten Sach (Linked List)", // Tu

    "Sap xep theo Ma Sach (Linked List)",  // Tu
    "Sap xep theo Ten Sach (Linked List)", // Minh

    // Nang cao
    "Duyet danh sach Preorder (BST)",  // Tu
    "Duyet danh sach Inorder (BST)",   // Duy
    "Duyet danh sach Postorder (BST)", // Minh

    "Tim kiem theo Ma Sach (BST)",  // Duy
    "Tim kiem theo Ten Sach (BST)", // Tu

    "Undo (Stack)",            // Minh
    "Them nhieu Sach (Queue)", // Tu

    "Thong ke Tong gia tri Sach (Linked List)",           // Duy
    "Thong ke So luong Sach theo The Loai (Linked List)", // Minh

    "Xem lich su thao tac", // Duy (file history.txt)

    "Doc danh sach Sach tu file",
    "Luu danh sach Sach vao file",
};

void menu()
{
    printf(
        "\n=========================================\n"
        "      HE THONG QUAN LY SACH THU VIEN      \n"
        "=========================================\n");

    for (int i = 0; i < 20; i++)
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
    printf(WHITE_BACKGROUND BLACK_TEXT "\nNhan Enter de tiep tuc..." RESET);
    getchar();

    clearScreen();
}

void clearScreen()
{
    // \e[1;1H di chuyen con tro ve vi tri (1,1)
    // \e[2J xoa toan bo man hinh
    printf("\e[1;1H\e[2J");
}

void stringToLower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}
