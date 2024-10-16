#include "string_utils.h"

// Hàm đếm độ dài chuỗi
int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Hàm sao chép chuỗi
void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Kết thúc chuỗi
}

// Hàm so sánh chuỗi
int my_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];  // Trả về sự khác biệt ký tự đầu tiên
        }
        i++;
    }
    // So sánh độ dài của hai chuỗi
    return str1[i] - str2[i];
}
