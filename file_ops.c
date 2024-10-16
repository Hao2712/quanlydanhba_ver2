#include <stdio.h>
#include "file_ops.h"

// Hàm mở file để ghi (write mode)
FILE *openFileForWrite(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi: %s\n", filename);
    }
    return file;
}

// Hàm mở file để đọc (read mode)
FILE *openFileForRead(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc: %s\n", filename);
    }
    return file;
}

// Hàm đóng file
void closeFile(FILE *file) {
    if (file != NULL) {
        fclose(file);
    }
}

// Hàm ghi một dòng vào file
void writeLineToFile(FILE *file, const char *line) {
    if (file != NULL) {
        fprintf(file, "%s\n", line);
    }
}

// Hàm đọc một dòng từ file
int readLineFromFile(FILE *file, char *buffer, int max_len) {
    if (file != NULL && fgets(buffer, max_len, file) != NULL) {
        return 1; // Đọc thành công
    }
    return 0; // Lỗi hoặc kết thúc file
}
