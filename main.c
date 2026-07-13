#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int choice = -1;

    do
    {
        choice = -1;

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
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== DANH SACH SACH =====\n" RESET);
            displayBooks(head);
            break;
        }

        case 3: // Sua thong tin 1 Sach
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

        case 4: // Xoa 1 Sach
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

        case 5: // Tim kiem theo ma sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 6: // Tim kiem theo ten sach (Linked List)
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== TIM KIEM THEO TEN SACH (LINKED LIST) =====\n" RESET);

            char tenSach[MAX_NAME];
            printf("Nhap ten sach can tim: ");
            scanf("%24[^\n]", tenSach);
            clearInputBuffer();

            Node *book = findBookByName(head, tenSach);

            if (book != NULL)
            {
                printf(GREEN_TEXT "\nTim thay sach:\n" RESET);
                displayBooks(book);
            }
            else
            {
                printf(YELLOW_TEXT "\nKhong tim thay sach!\n" RESET);
            }

            break;
        }

        case 7: // Sap xep theo ma sach (Linked List)
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== SAP XEP THEO MA SACH (LINKED LIST) =====\n" RESET);
            sortBooksById(&head);
            displayBooks(head);
            break;
        }

        case 8: // Sap xep theo ten sach (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 9: // Duyet danh sach Preorder (BST)
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== DUYET DANH SACH PREORDER (BST) =====\n" RESET);

            BSTRoot root = NULL;
            insertBSTNodeFromLinkedList(&root, head);

            Node *result = browsePreorder(root);
            displayBooks(result);
            break;
        }

        case 10: // Duyet danh sach Inorder (BST)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 11: // Duyet danh sach Postorder (BST)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 12: // Tim kiem theo Ma Sach (BST)
            printf("\nChuc nang dang phat trien...\n");
            break;

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

        case 19: // Doc danh sach Sach tu file
        {
            freeList(&head);
            loadList(&head);
            printf(GREEN_TEXT "\nDoc danh sach sach tu file thanh cong!\n" RESET);
            break;
        }

        case 20: // Luu danh sach Sach vao file
        {
            saveList(head);
            printf(GREEN_TEXT "\nLuu danh sach sach vao file thanh cong!\n" RESET);
            break;
        }

        case 0:
            printf("\nCam on ban da su dung chuong trinh!\n");
            break;

        default:
            printf("\nLua chon khong hop le!\n");
            break;
        }

        if (choice != 0)
            pauseScreen();

    } while (choice != 0);

    return 0;
}
