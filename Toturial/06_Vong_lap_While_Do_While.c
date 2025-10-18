/*
1. Cú pháp vòng lặp while
    while (điều kiện lặp) {
        code;
    }
    vòng lặp cho đến khi điều kiện lặp bị sai

2. Cú pháp vòng lặp do while
    do {
        code;
    } while (điều kiện lặp);
    lặp cho đến khi điều kiện lặp bị sai
    thực hiện ít nhất khối lệnh 1 lần
*/

#include <stdio.h>

int main() {
    int i = 1;    
    // vòng lặp có nhiều câu lệnh phải có {}
    while (i < 10) {
        printf("%d", i);
        ++i;
        if ( i == 5) break;
    }
    
    // Vòng lặp vô hạn là vòng lặp có điều kiện lặp luôn đúng hoặc không có câu lệnh tăng/giảm biến chạy
    while (1);
    // vòng lặp với 1 câu lệnh có thể bỏ {}
    while (i == 1) printf("Xin chao");
    
    // Vòng lặp do while
    do {
        printf("Giá trị cua biến i : %d ", i);
        i++;
    } while (i <=5);

    return 0;
}