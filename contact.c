#include "contact.h"
#include "string_utils.h"
#include "UI.h"
#include "file_handler.h"
#include <stdio.h>

// Hàm thêm liên lạc mới vào danh bạ
void addContact(Contact *contacts, int *size, Contact new_contact) {
    if (*size >= 100) {  // Giả sử danh bạ có tối đa 100 liên lạc
        showMessage("Danh ba da day, khong the them lien lac moi.\n");
        return;
    }
    contacts[*size] = new_contact;
    (*size)++;
}

// Hàm xóa liên lạc khỏi danh bạ dựa trên số điện thoại
int deleteContact(Contact *contacts, int *size, const char *phone) {
    for (int i = 0; i < *size; i++) {
        if (my_strcmp(contacts[i].phone, phone) == 0) {
            // Dịch chuyển các phần tử phía sau để lấp vào vị trí bị xóa
            for (int j = i; j < (*size) - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            return 1;  // Xóa thành công
        }
    }
    return 0;  // Không tìm thấy liên lạc cần xóa
}

// Hàm sửa thông tin liên lạc dựa trên số điện thoại
void editContact(Contact *contacts, int size, const char *phone, Contact new_info) {
    for (int i = 0; i < size; i++) {
        if (my_strcmp(contacts[i].phone, phone) == 0) {
            contacts[i] = new_info;  // Cập nhật thông tin liên lạc
            return;
        }
    }
}

// Hàm tìm kiếm liên lạc dựa trên số điện thoại
Contact* searchContactByPhone(Contact *contacts, int size, const char *phone) {
    for (int i = 0; i < size; i++) {
        if (my_strcmp(contacts[i].phone, phone) == 0) {
            return &contacts[i];
        }
    }
    return NULL;  // Không tìm thấy liên lạc
}

// Hàm tìm kiếm liên lạc dựa trên tên
Contact* searchContactByName(Contact *contacts, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (my_strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;  // Không tìm thấy liên lạc
}

// Hàm hiển thị thông tin liên lạc
void displayContact(const Contact *contact) {
    showMessage("Ten: ");
    showMessage(contact->name);
    showMessage("So dien thoai: ");
    showMessage(contact->phone);
    showMessage("Email: ");
    showMessage(contact->email);
    showMessage("Dia chi: ");
    showMessage(contact->address);
}

void stdPhone(int phone, char *contact) {
    if(!phone) {
        printf("So dien thoai sai dinh dang\n");
        inputString("Nhap lai so dien thoai: ", contact, 15);
    }
}

void stdEmail(int email, char *contact) {
    if(!email) {
        printf("Email sai dinh dang\n");
        inputString("Nhap lai email: ", contact, 50);
    }
}