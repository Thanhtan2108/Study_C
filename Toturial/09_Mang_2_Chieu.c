/*
1. Cú pháp khai báo mảng 2 chiều
    kiểu_dữ_liệu tên_mảng[số_hàng][số_cột];
    có thể bỏ trống số hàng nhưng ko được bỏ trống số cột

2. Nhập giá trị cho mảng 2 chiều
    Dùng 2 vòng for lồng nhau để nhập
    nhập tương tự mảng 1 chiều
*/


#include <stdio.h>

void nhapMang(int a[][100], int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            printf("Nhap gia tri phan tu thu [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void inMang(int a[][100], int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            printf("Gia tri phan tu thu [%d][%d]: %d\n", i, j, a[i][j]);
        }
    }
}

int main() {
    // khởi tạo 1 mảng 2 chiều cho trước giá trị
    int b[2][3] = {{0,1,2},{1,2,3}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("b[%d][%d] = %d\n", i, j, b[i][j]);
        }
    }
    int n,m;
    scanf("%d %d", &n, &m);
    int a[100][100]; // Sử dụng mảng cố định với kích thước tối đa
    nhapMang(a, n, m);
    inMang(a, n, m);
    return 0;
}