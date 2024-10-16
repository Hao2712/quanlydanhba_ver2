#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "contact.h"  // Bao gồm tệp tiêu đề contact.h để định nghĩa kiểu Contact


// Struct lưu thông tin về một tùy chọn trong menu
typedef struct {
    int option_number;                // Số tùy chọn
    char feature_name[50];            // Tên tính năng
    void (*handler)(Contact *);       // Con trỏ hàm để thực hiện chương trình
} MenuOption;

// Hàm hiển thị menu và nhận lựa chọn của người dùng
void displayMenu(MenuOption menu_options[], int menu_size, Contact *contacts);

// Hàm nhập chuỗi có kiểm tra
void inputString(const char* prompt, char* input, int max_len);

// Hàm nhập số nguyên có kiểm tra
int inputInt(const char* prompt);

// Hàm hiển thị thông báo
void showMessage(const char* message);

// Hàm thoát chương trình
void exitProgram(Contact *contacts);

#endif // UI_H
