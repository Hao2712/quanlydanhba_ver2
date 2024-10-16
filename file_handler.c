#include <stdio.h>
#include "file_handler.h"
#include "file_ops.h"
#include <stdlib.h>  // Bao gồm stdlib.h để sử dụng hàm atoi

// Hàm lưu danh bạ vào file
int saveContactsToFile(Contact *contacts, int size, const char *filename) {
    // Mở file để ghi
    FILE *file = openFileForWrite(filename);
    if (file == NULL) {
        return 0; // Lỗi khi mở file
    }

    // Ghi số lượng liên lạc vào file
    char line[256];
    snprintf(line, sizeof(line), "%d", size);
    writeLineToFile(file, line);

    // Ghi từng liên lạc vào file
    for (int i = 0; i < size; i++) {
        snprintf(line, sizeof(line), "%s,%s,%s,%s", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address);
        writeLineToFile(file, line);
    }

    // Đóng file
    closeFile(file);
    return 1;
}

// Hàm đọc danh bạ từ file
int loadContactsFromFile(Contact *contacts, const char *filename) {
    // Mở file để đọc
    FILE *file = openFileForRead(filename);
    if (file == NULL) {
        return 0; // Lỗi khi mở file
    }

    // Đọc số lượng liên lạc từ file
    char line[256];
    if (readLineFromFile(file, line, sizeof(line))) {
        int size = atoi(line);  // Chuyển số lượng liên lạc từ chuỗi thành số nguyên
        if (size > MAX_CONTACTS) {
            printf("So luong lien lac trong file vuot qua gioi han cho phep.\n");
            closeFile(file);
            return 0;
        }

        // Đọc từng liên lạc từ file
        for (int i = 0; i < size; i++) {
            if (readLineFromFile(file, line, sizeof(line))) {
                sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address);
            }
        }

        // Đóng file sau khi đọc xong
        closeFile(file);
        return size; // Trả về số lượng liên lạc đã đọc
    }

    closeFile(file);
    return 0;
}
