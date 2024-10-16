#include "contact_manager.h"
#include "UI.h"
#include "contact.h"
#include "file_handler.h"
#include "type_valid.h"
#include <stdio.h>

char *file_name = "phone_book.csv";
// Số lượng liên lạc hiện tại trong danh bạ
static int contact_count = 0;  // Được quản lý trong nội bộ các hàm

// Hàm thêm liên lạc mới và xử lý thông tin
void addNewContact(Contact *contacts) {
    contact_count = loadContactsFromFile(contacts, file_name);
    if (contact_count >= 100) {
        showMessage("Danh ba đa đay, khong the them lien lac moi.\n");
        return;
    }

    Contact new_contact;
    inputString("Nhap ten: ", new_contact.name, 50);
    inputString("Nhap so dien thoai: ", new_contact.phone, 15);
    int phone = isValidPhone(new_contact.phone);
    stdPhone(phone, new_contact.phone);
    inputString("Nhap email: ", new_contact.email, 50);
    int email = isValidEmail(new_contact.email);
    stdEmail(email, new_contact.email);
    inputString("Nhap dia chi: ", new_contact.address, 100);

    addContact(contacts, &contact_count, new_contact);  // Thêm liên lạc vào danh bạ
    saveContactsToFile(contacts, contact_count, file_name);
    showMessage("Lien lac da duoc them thanh cong:\n");
    displayContact(&new_contact);  // Hiển thị liên lạc mới thêm
}

// Hàm xóa liên lạc theo số điện thoại
void deleteExistingContact(Contact *contacts) {
    contact_count = loadContactsFromFile(contacts, file_name);
    if (contact_count == 0) {
        showMessage("Danh ba trong, khong co lien lac nao de xoa.\n");
        return;
    }

    char phone[15];
    inputString("Nhap so dien thoai cua lien lac can xoa: ", phone, 15);

    if (deleteContact(contacts, &contact_count, phone)) {
        showMessage("Xoa lien lac thanh cong.\n");
        saveContactsToFile(contacts, contact_count, file_name);
    } else {
        showMessage("Khong tim thay lien lac voi so dien thoai nay.\n");
    }
}

// Hàm sửa thông tin liên lạc
void editExistingContact(Contact *contacts) {
    contact_count = loadContactsFromFile(contacts, file_name);
    if (contact_count == 0) {
        showMessage("Danh ba trong, khong co lien lac nao de sua.\n");
        return;
    }

    char phoneNumber[15];
    inputString("Nhap so dien thoai cua lien lac can sua: ", phoneNumber, 15);

    Contact *contact = searchContactByPhone(contacts, contact_count, phoneNumber);
    if (contact == NULL) {
        showMessage("Khong tim thay lien lac voi so dien thoai nay.\n");
        return;
    }

    Contact new_info;
    inputString("Nhap ten moi: ", new_info.name, 50);
    inputString("Nhap so dien thoai moi: ", new_info.phone, 15);
    int phone = isValidPhone(new_info.phone);
    stdPhone(phone, new_info.phone);
    inputString("Nhap email moi: ", new_info.email, 50);
    int email = isValidEmail(new_info.email);
    stdEmail(email, new_info.email);
    inputString("Nhap dia chi moi: ", new_info.address, 100);

    editContact(contacts, contact_count, phoneNumber, new_info);
    saveContactsToFile(contacts, contact_count, file_name);
    showMessage("Lien lac da duoc cap nhat.\n");
}

// Hàm tìm kiếm liên lạc theo số điện thoại
void searchContactByPhoneUI(Contact *contacts) {
    contact_count = loadContactsFromFile(contacts, file_name);
    if (contact_count == 0) {
        showMessage("Danh ba trong, khong co lien lac nao de tim.\n");
        return;
    }

    char phone[15];
    inputString("Nhap so dien thoai de tim kiem: ", phone, 15);

    Contact *contact = searchContactByPhone(contacts, contact_count, phone);
    if (contact != NULL) {
        showMessage("Lien lac tim thay:\n");
        displayContact(contact);
    } else {
        showMessage("Khong tim thay lien lac.\n");
    }
}

// Hàm tìm kiếm liên lạc theo tên
void searchContactByNameUI(Contact *contacts) {
    contact_count = loadContactsFromFile(contacts, file_name);
    if (contact_count == 0) {
        showMessage("Danh ba trong, khong co lien lac nao de tim.\n");
        return;
    }

    char name[50];
    inputString("Nhap ten de tim kiem: ", name, 50);

    Contact *contact = searchContactByName(contacts, contact_count, name);
    if (contact != NULL) {
        showMessage("Lien lac tim thay:\n");
        displayContact(contact);
    } else {
        showMessage("Khong tim thay lien lac.\n");
    }
}

// Hàm hiển thị toàn bộ danh bạ
void displayAllContacts(Contact *contacts) {
    contact_count = loadContactsFromFile(contacts, file_name);
    // Kiểm tra nếu danh bạ trống
    if (contact_count == 0) {
        showMessage("Danh ba trong.");
        return;
    }

    // Duyệt qua danh bạ và hiển thị từng liên lạc
    for (int i = 0; i < contact_count; i++) {
        char message[100];
        snprintf(message, sizeof(message), "\nLien lac %d:\n", i + 1);
        showMessage(message);  // Hiển thị số thứ tự của liên lạc

        // Hiển thị chi tiết liên lạc
        displayContact(&contacts[i]);
    }
}

