#include "UI.h"
#include "string_utils.h"
#include "contact_manager.h"
#include <stdlib.h>

void displayMenu(MenuOption menu_options[], int menu_size, Contact *contacts) {
    for (int i = 0; i < menu_size; i++) {
        printf("%d. %s\n", menu_options[i].option_number, menu_options[i].feature_name);
    }

    int choice = inputInt("Chon tinh nang: ");

    int valid_choice = 0;
    for (int i = 0; i < menu_size; i++) {
        if (choice == menu_options[i].option_number) {
            menu_options[i].handler(contacts);  // Gọi hàm tương ứng với tùy chọn được chọn
            valid_choice = 1;
            break;
        }
    }

    if (!valid_choice) {
        showMessage("Lua chon khong hop le, vui long thu lai.");
    }
}

void inputString(const char* prompt, char* input, int max_len) {
    printf("%s", prompt);
    fgets(input, max_len, stdin);
    // Xóa bỏ ký tự xuống dòng ở cuối chuỗi
    size_t len = my_strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

int inputInt(const char* prompt) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1) {
        while (getchar() != '\n');  // Xóa bỏ đầu vào lỗi
        printf("Dau vao khong hop le. Vui long nhap lai: ");
    }
    while (getchar() != '\n');  // Xóa bỏ dòng trống sau khi nhập
    return input;
}

void showMessage(const char* message) {
    printf("%s\n", message);
}

void exitProgram(Contact *contacts) {
    printf("Thoat chuong trinh");
    exit(0);
}
