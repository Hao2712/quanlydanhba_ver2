#include "UI.h"
#include "contact_manager.h"
#include "contact.h"
#include "file_handler.h"

#define MAX_CONTACTS 100

int main() {
    Contact contacts[MAX_CONTACTS];  // Khai báo danh sách liên lạc

    // Định nghĩa các tùy chọn menu
    MenuOption menu_options[] = {
        {1, "Them lien lac", addNewContact},
        {2, "Xoa lien lac", deleteExistingContact},
        {3, "Sua lien lac", editExistingContact},
        {4, "Tim kiem lien lac theo so dien thoai", searchContactByPhoneUI},
        {5, "Tim kiem lien lac theo ten", searchContactByNameUI},
        {6, "Hien thi tat ca lien lac", displayAllContacts},
        {0, "Thoat chuong trinh.", exitProgram}
    };

    int menu_size = sizeof(menu_options) / sizeof(menu_options[0]);  // Kích thước menu

    // Vòng lặp chính để hiển thị menu và nhận lựa chọn từ người dùng
    while (1) {
        printf("\n=== MENU QUAN LY DANH BA ===\n");
        displayMenu(menu_options, menu_size, contacts);  // Hiển thị menu và xử lý lựa chọn

        int exit_choice = inputInt("Nhap 0 de thoat hoac 1 de quay lai menu: ");
        while (exit_choice != 1 && exit_choice != 0) {
            exit_choice = inputInt("Nhap 0 de thoat hoac 1 de quay lai menu: ");
        }
        if (exit_choice == 0) {
            exitProgram(contacts);
        }
    }

    return 0;
}
