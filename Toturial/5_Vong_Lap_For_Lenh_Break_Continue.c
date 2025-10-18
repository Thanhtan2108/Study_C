/*
1. Cú pháp vòng lặp for:
    for (lệnh khởi tạo biến chạy ; điều kiện lặp ; lệnh cập nhật giá trị biến chạy) {
        khối lệnh;
    }

Vòng for còn lặp khi điều kiện lặp còn đúng, khi điều kiện lặp sai sẽ thoát vòng for

2. Lệnh break;
    thoát khỏi vòng lặp ngay khi gặp lệnh break; bất kể trong vòng lặp còn lệnh hay không

3. Lệnh continue;
    chỉ dùng trong vòng lặp
    khi gặp lệnh cotinue; các câu lệnh trong vòng lặp hiện tại còn lại được bỏ qua và bắt đầu 1 vòng lặp mới

4. 2 vòng for lồng nhau:
    for () {
        for () {
        
        }
    }
    thường dùng để duyệt qua các phần tử có được quản lý bởi 1 phần tử lớn hơn
*/

// Các ví dụ bên dưới, muốn chạy trường hợp nào thì bỏ command phần đó bằng ctrl + /
#include <stdio.h>

int main() {
    // Lặp hữu hạn
    // for (int i = 1 ; i <= 5 ; i++) {
    //     printf("%d ", i);
    // }

    // for (int i = 1 ; i <= 5 ; i += 2) {
    //     printf("%d ", i);
    // }

    // for (int i = 1 ; i >= 1 && i <= 10 ; i++) {
    //     printf("%d ", i);
    //     continue;
    // }

    // int n, sum = 0; scanf("%d", &n);
    // for (int i = 0 ; i < n ; i++) {
    //     sum += i;
    //     if (i == 5) break;
    // }
    // printf("Tong là: %d", sum);

    // Lặp vô hạn
    // for (int i = 1 ; ; i++) {
    //     printf("%d ", i);
    // }

    // for (int i = 1 ; i <= 5 ; ) {
    //     printf("%d ", i);
    // }

    // for ( ; ; ) {
    //     printf("Xin chào\n");
    // }

    // 2 for lồng nhau
    // for (int i = 0 ; i < 3 ; i++) {
    //     for (int j = 0 ; j < 4 ; j++) {
    //         printf("%d%d ", i, j);
    //     }
    //     printf("\n");
    // }

    return 0;
}