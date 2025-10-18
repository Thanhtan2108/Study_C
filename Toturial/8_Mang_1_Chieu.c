/*
Muốn lưu các phần tử có cùng kiểu dữ luệ thì có thể tóm gọn lại thành 1 mảng
1. Cú pháp khai báo mảng: 
    kiểu_dữ_liệu_các_phần_tử_trong_mảng tên_mảng[kích_thước_phần_tử_của_mảng];
    các phần tử trong mảng có thứ tự đếm(index) bắt đầu từ 0

2. Muốn nhập giá trị cho 1 phần tử trong mảng
    bởi vì các phần tử trong mảng được lưu là 1 danh sách các ô địa chỉ nằm gần nhau nên muốn nhập giá trị cho phần tử nào cần chỉ định rõ địa chỉ phần tử đó 
    scanf("đặt_tả_của_phần_tử_trong_mảng", &tên_mảng[thứ_tự_phần_tử_trong_mảng_cần_nhập_giá_trị]);

3. Muốn in ra giá trị 1 phần tử trong mảng
    printf("đặt_tả_của_phần_tử_cần_in", tên_mảng[thứ_tự_phần_tử_cần_in_trong_mảng]);

4. Viết hàm truyền tham số là mảng thì sẽ thực hiện theo kiểu truyền tham chiếu

5. Nếu khai báo 1 mảng có số lượng phần tử quá lớn dẫn đến lỗi tràn bộ nhớ heap, cách giải quyết là khai báo mảng đó bên ngoài hàm main()
*/

#include <stdio.h>

void nhapMang(int a[], int n) {
    printf("Nhap cac phan tu trong mang\n");
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
}

void inMang(int a[], int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("Gia tri cua phan tu thu %d: %d\n", i, a[i]);
    }
}
int main() {
    // int a[100]; // mảng có 100 phần tử số nguyên
    // scanf("%d", &a[1]);
    // printf("phần tử thứ 2 trong mảng là: %d", a[1]);
    
    // khởi tạo mảng và nhập giá trị cho mảng đã biết trước kích thước phần tử
    // int b [5]; // mảng có 5 phần tủ số bouble
    // for (int i = 0 ; i < 5 ; i++) {
    //     printf("Nhập giá trị cho phần tử thứ %d: ", i);
    //     scanf("%d", &b[i]);
    // }

    // in ra các phần tử trong mảng đã biết trước kích thước phần tử
    // for (int i = 0 ; i < 5 ; i++) {
    //     printf("%d ", b[i]);
    // }

    // Khai báo và nhập số lượng phần tử của mảng
    int n; 
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    //khai báo mảng đã có n phần tử nhập từ bàn phím
    int c[n];
    nhapMang(c, n);
    inMang(c, n);

    // Khai báo 1 mảng có tất cả các giá trị bằng 0
    // int d[5] = {0};

    return 0;
}