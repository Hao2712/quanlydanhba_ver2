#ifndef FILE_OPS_H
#define FILE_OPS_H

// Hàm mở file để ghi
FILE *openFileForWrite(const char *filename);

// Hàm mở file để đọc
FILE *openFileForRead(const char *filename);

// Hàm đóng file
void closeFile(FILE *file);

// Hàm ghi một dòng vào file
void writeLineToFile(FILE *file, const char *line);

// Hàm đọc một dòng từ file
int readLineFromFile(FILE *file, char *buffer, int max_len);

#endif // FILE_OPS_H
