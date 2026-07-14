#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/book.h"
#include "include/linkedlist.h"
#include "include/file.h"
#include "include/utils.h"
#include "include/queue.h"
#include "include/bst.h"
#include "include/history.h"

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
            scanf("%6s", maSach);

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
            scanf("%6s", maSach);

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
            scanf("%29[^\n]", tenSach);
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
                displayBooks(book);
            }
            else
            {
                printf("\nKhong tim thay sach!\n");
            }
        }

        break;

        case 13: // Tim kiem theo Ten Sach (BST)
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== TIM KIEM THEO TEN SACH (BST) =====\n" RESET);

            BSTRoot root = NULL;
            insertBSTNodeForNameFromLinkedList(&root, head);

            char tenSach[MAX_NAME];
            printf("Nhap ten sach can tim: ");
            scanf("%29[^\n]", tenSach);
            clearInputBuffer();

            Node *book = searchByBookName(root, tenSach);

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
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== THONG KE TONG GIA TRI SACH (LINKED LIST) =====\n" RESET);

            if (head == NULL)
            {
                printf(YELLOW_TEXT "Danh sach rong!\n" RESET);
            }
            else
            {
                float totalValue = totalBookValue(head);
                printf(GREEN_TEXT "Tong gia tri cua tat ca sach: %.0f VND\n" RESET, totalValue);
            }
            break;
        }

        case 17: // Thong ke So luong Sach theo The Loai (Linked List)
            printf("\nChuc nang dang phat trien...\n");
            break;

        case 18: // Xem lich su thao tac
        {
            clearScreen();
            printf(GREEN_BACKGROUND "\n===== LICH SU THAO TAC =====\n" RESET);
            showHistory();
            break;
        }

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
