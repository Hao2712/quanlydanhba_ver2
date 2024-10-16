#ifndef CONTACT_H
#define CONTACT_H


// Định nghĩa một cấu trúc cho liên lạc
typedef struct {
    char name[50];        // Tên liên lạc
    char phone[15];       // Số điện thoại
    char email[50];       // Email
    char address[100];    // Địa chỉ
} Contact;

// Khai báo các hàm cần thiết để thao tác với danh bạ
void addContact(Contact *contacts, int *size, Contact new_contact);
int deleteContact(Contact *contacts, int *size, const char *phone);
void editContact(Contact *contacts, int size, const char *phone, Contact new_info);
Contact* searchContactByPhone(Contact *contacts, int size, const char *phone);
Contact* searchContactByName(Contact *contacts, int size, const char *name);
void displayContact(const Contact *contact);
void stdPhone(int phone, char *contact);
void stdEmail(int email, char *contact);

#endif // CONTACT_H
