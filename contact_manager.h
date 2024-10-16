#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "contact.h"  // Bao gồm tệp tiêu đề contact.h để định nghĩa kiểu Contact

// Khai báo các hàm quản lý danh bạ với chỉ một tham số đầu vào là danh sách liên lạc
void addNewContact(Contact *contacts);
void deleteExistingContact(Contact *contacts);
void editExistingContact(Contact *contacts);
void searchContactByPhoneUI(Contact *contacts);
void searchContactByNameUI(Contact *contacts);
void displayAllContacts(Contact *contacts);

#endif // CONTACT_MANAGER_H
