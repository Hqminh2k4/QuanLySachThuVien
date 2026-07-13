#include <stdio.h>

#include "include/book.h"
#include "include/linkedlist.h"
#include "include/utils.h"

int main()
{
    Node *head = NULL;
    int choice;

    do
    {
        menu();

        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        clearInputBuffer();

        switch (choice)
        {
        case 1:
            printf("\nChuc nang nhap danh sach dang phat trien...\n");
            break;

        case 2:
            Book book = inputBook(head);
            addLast(&head, book);

            printf("\nThem sach thanh cong!\n");
            break;

        case 3:
            // Cap nhat
        {
            char maSach[MAX_ID];

            printf("Nhap ma sach can cap nhat: ");
            scanf("%19s", maSach);

            if (updateBook(head, maSach))

                printf("\nCap nhat thanh cong!\n");

            else
                printf("\nKhong tim thay sach!\n");

            break;
        }
        case 4:
            // Xoa
        {
            char maSach[MAX_ID];

        printf("Nhap ma sach can xoa: ");
        scanf("%19s", maSach);

        if (deleteBook(&head, maSach))
            printf("\nXoa thanh cong!\n");
        else
            printf("\nKhong tim thay sach!\n");
        break;
        }
        case 0:
            printf("\nCam on ban da su dung chuong trinh!\n");
            break;

        default:
            printf("\nLua chon khong hop le!\n");
        }

        if (choice != 0)
            pauseScreen();

    } while (choice != 0);

    return 0;
}