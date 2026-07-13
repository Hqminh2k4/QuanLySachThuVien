#ifndef UTILS_H
#define UTILS_H

#define BLACK_TEXT "\033[30m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define RED_BACKGROUND "\033[41m"
#define GREEN_BACKGROUND "\033[42m"
#define YELLOW_BACKGROUND "\033[43m"
#define WHITE_BACKGROUND "\033[47m"
#define RESET "\033[0m"

// Hiển thị menu chính
void menu();

// Xóa dữ liệu còn trong bộ đệm bàn phím
void clearInputBuffer();

// Tạm dừng màn hình
void pauseScreen();

void clearScreen();

/*
 * Chuyển chuỗi thành chữ thường
 * Lưu ý: Chuỗi truyền vào sẽ bị thay đổi trực tiếp
 */
void stringToLower(char *str);

#endif