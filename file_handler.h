#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "contact.h"

// Định nghĩa kích thước tối đa của danh bạ
#define MAX_CONTACTS 100

// Hàm ghi danh bạ vào file
int saveContactsToFile(Contact *contacts, int size, const char *filename);

// Hàm đọc danh bạ từ file
int loadContactsFromFile(Contact *contacts, const char *filename);

#endif // FILE_HANDLER_H
