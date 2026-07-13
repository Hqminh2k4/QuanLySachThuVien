#include <stdio.h>
#include <stdlib.h>

#include "include/book.h"
#include "include/linkedlist.h"
#include "include/file.h"
#include "include/utils.h"
#include "include/queue.h"
#include "include/bst.h"

int main()
{
    Node *head = NULL;
    loadList(&head);

    int choice;

    do
    {
        menu();

        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        clearInputBuffer();

        switch (choice)
        {
        case 1: // Them 1 Sach vao cuoi
            Book book = inputBook(head);
            addLast(&head, book);

            printf("\nThem sach thanh cong!\n");
            break;

        case 2: // Hien thi danh sach Sach
            displayBooks(head);
            break;

        case 3: // Sua thong tin 1 Sach
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 4: // Xoa 1 Sach
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 5: // Tim kiem theo ma sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 6: // Tim kiem theo ten sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 7: // Sap xep theo ma sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 8: // Sap xep theo ten sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 9: // Duyet danh sach Preorder (BST)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 10: // Duyet danh sach Inorder (BST)
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== DUYET DANH SACH INORDER (BST) =====\n" RESET);

            BSTNode *root = NULL;

            buildBSTFromList(&root, head);

            if (root == NULL)
            {
                printf(YELLOW_TEXT "\nDanh sach rong!\n" RESET);
            }
            else
            {
                printf("%-6s %-25s %-25s %-20s %-25s %6s %10s %4s\n",
                    "Ma",
                    "Ten sach",
                    "Tac gia",
                    "The loai",
                    "Nha XB",
                    "Nam",
                    "Gia",
                    "SL");

                printf("---------------------------------------------------------------------------------------------------------------\n");

                inorder(root);
        }

        break;
}

        case 11: // Duyet danh sach Postorder (BST)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 12: // Tim kiem theo Ma Sach (BST)
        {
            BSTNode *root = NULL;
            buildBSTFromList(&root, head);

             char maSach[MAX_ID];

            printf("Nhap ma sach can tim: ");
            scanf("%19s", maSach);

            BSTNode *book = findBookByIdBST(root, maSach);

            if (book != NULL)
            {
                    printf("\nTim thay sach!\n");
                    displayBookBST(book);
            }
            else
            {
                printf("\nKhong tim thay sach!\n");
            }
        }

        break;
}
        case 13: // Tim kiem theo Ten Sach (BST)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 14: // Undo (Stack)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 15: // Them nhieu Sach (Queue)
        {
            Queue queue;
            initQueue(&queue);

            clearScreen();
            printf(GREEN_BACKGROUND "\n===== NHAP NHIEU SACH (QUEUE) =====\n" RESET);
            char answer;
            do
            {
                Book book = inputBook(head);
                enqueue(&queue, createNode(book));

                printf(GREEN_TEXT "Ban co muon nhap them sach khong? (y/n): " RESET);
                clearInputBuffer();
                scanf("%c", &answer);
            } while (answer != 'n' && answer != 'N');

            while (!isEmpty(&queue))
            {
                Node *node = dequeue(&queue);
                addLast(&head, node->data);
                free(node);
            }

            saveList(head);
        }
        break;

        case 16: // Thong ke Tong gia tri Sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 17: // Thong ke So luong Sach theo The Loai (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 18: // Xem lich su thao tac
            printf("\nChuc nang dang phat trien...\n");
            break;

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
