/*
1. Biến con trỏ là biến đtawj biệt thay vì nó lưu giá trị của 1 biến thì nó lại lưu địa chỉ của 1 biến khác mà nó sẽ quản lý

2. Cách khai báo 1 con trỏ
    kiểu_dữ_liệu *tên_biến_con_trỏ;

3. dùng con trỏ để quản lý 1 biến khác thông qua địa chỉ của biến đó và biến đó phải cùng kiểu dữ liệu với con trỏ
    nên giá trị của biến con trỏ là 1 địa chỉ của biến cần quản lý
    ptr = &a;

4. Con trỏ chưa có giá trị địa chỉ thì nó sẽ có giá trị NULL

5. Có các toán tử được dùng với bài con trỏ như sau:
    &: toán tử lấy địa chỉ của biến, thường dùng để lấy địa chỉ của 1 biến làm giá trị cho biến con trỏ quản lý
    *: toán tử lấy giá trị của 1 biến được biến con trỏ quản lý thông qua địa chỉ của biến đó

6. Có thể dùng con trỏ để thay đổi giá trị của biến mà nó quản lý 1 cách trực tiếp.

7. Xây dựng hàm truyền con trỏ làm tham số cho hàm, tương đương với truyền tham chiếu, sau khi kết thúc hàm thì giá trị đối số sẽ thay đổi
    kiểu_dữ_liệu_trả_về tên_hàm(kiểu_dữ_liệu_con_trỏ *tên_con_trỏ) {
        code;
    }

    trong lời gọi hàm, đối số truyền vào là giá trị của 1 biến, trong trường hợp này giá trị của biến con trỏ là địa chỉ của 1 biến khác nên cần truyền địa chỉ của biến đó làm đối số
    tên_hàm(&tên_biến_được_con_trỏ_quản_lý);

8. Mối liên hệ giữa mảng và con trỏ
    tên mảng được coi như là hằng con trỏ => 1 biến con trỏ, giá trị của biến này là giá trị của phần tử đầu tiên(index = 0) trong mảng đó.

    Nếu lúc này gán 1 biến con trỏ = tên_mảng, thì lúc này biến con trỏ sẽ quản lý mảng đó nhưng thay vì làm việc với các giá trị của các phần tử trong mảng thì lúc này mình sẽ làm việc với các địa chỉ của phần tử trong mảng (thường là làm việc với index của mảng) đó.

    &a[i] == a + i; bởi vì nôm na a + i là 1 con trỏ trỏ đến phần tử thứ i trong mảng, giá trị chỉ định là địa chỉ của phần tử thứ i trong mảng

    a[i] == *(a + i); bởi vì a + i là con trỏ nó quản lý địa chỉ của phần tử thứ i trong mảng, cần biết giá trị của phần tử thứ i đó cần toán tử giải tham chiếu * để lấy giá trị của phần tử thứ i đó.

    toán tử ++ : sẽ làm cho con trỏ di chuyển tăng thêm 1 đơn vị index trong mảng.
    toán tử -- : sẽ làm cho con trỏ di chuyển giảm thêm 1 đơn vị index trong mảng
    toán tử += i : sẽ làm cho con trỏ nhảy cóc đến phần tử index thứ i trong mảng
    toán tử -= i : sẽ làm con trỏ thụt lùi đến phần tử index thứ i trong mảng

9. Cấp phát động bằng malloc(), để giải quyết lỗi tràn bộ nhớ stack khi phần tử trong mảng quá lớn. Cách giải quyết là xin cấp phát động 1 con trỏ(trương đương 1 mảng) bằng malloc(), vì malloc() trả về là 1 con trỏ void nên cần phải ép kiểu cho nó.
    kiểu_dữ_liệu *tên_con_trỏ = (kiểu_dữ_liệu *)malloc(sizeof(kiểu_dữ_liệu) * số_lượng_phần_tử);

Sau khi làm việc với mảng cấp phát động xong và cần trả lại bộ nhớ thì dùng hàm free(tên_con_trỏ) để giải phóng bộ nhớ
*/

#include <stdio.h>

// hàm truyền tham trị, không thay đổi giá trị đối số
void tang1(int a) {
    a += 100;
}

// hàm truyền tham chiếu, truyền con trỏ, thay giá trị đối số
void tang2(int *a) {
    *a += 100;
} 

int main() {
    int a = 300;
    //khai báo con trỏ
    int *ptr;
    // gán địa chỉ của biến a cho con trỏ ptr, lúc này con trỏ ptr sẽ quản lý trực tiếp biến a
    ptr = &a;
    printf("Dia chi cua bien a la : 0x%X\n", &a);
    printf("Gia tri cua bien con tro ptr la: 0x%X\n", ptr);
    //
    printf("Gia tri cua bien a: %d\n", a);
    printf("Gia tri cua bien ma con tro ptr quan ly: %d\n", *ptr);
    //
    *ptr = 1000; // thay a = 300 -> 1000
    printf("Gia tri cua bien a: %d\n", a);
    printf("Gia tri cua bien ma con tro ptr quan ly: %d\n", *ptr);
    //
    tang1(a);
    printf("Gia tri cua a khi thuc hien truyen tham tri: %d\n", a);
    tang2(&a);
    printf("Gia tri cua a sau khi thuc hien truyen tham chieu: %d\n", a);
    //
    int x[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("Dia chi cua phan tu dau tien trong mang: 0x%X\n", &x[0]);
    printf("Gia tri cua bien hang con tro x la: 0x%X\n", x);
    //
    int *y = x; // khai báo con trỏ quản lý mảng x
    for (int i = 0 ; i < 10 ; i++) {
        printf("Gia tri cua phan tu thu %d: %d\n", i, y[i]);
    }
    // 
    int d[5];
    // Nhập mảng
    for (int i = 0 ; i < 5 ; i++) {
        scanf("%d", d + i); // thay cho scanf("%d", &d[i]);
    }
    //Xuất mảng
    for (int i = 0 ; i < 5 ; i++) {
        printf("%d", *(d + i)); // thay cho printf("%d", d[i]);
    }
    //
    int e[5] = {1,2,3,4,5};
    int *f = e;
    ++f;
    printf("%d\n", *f); // in giá trị phần tử tại vị trí index thứ 1
    --f;
    printf("%d\n", *f); // in ra giá trị phần tử tại vị trí index thứ 0
    f += 3;
    printf("%d\n", *f); // in ra giá trị phần tử tại vị trí index thứ 3
    //
    int *g = (int *)malloc(1000 * sizeof(int)); // cấp phát động 1 mảng 1000 phần tử kiểu int được quản lý bởi con trỏ g
    int h = 5;
    for (int i = 0 ; i < h ; i++) {
        scanf("%d", &g[i]);
    }
    for (int i = 0 ; i < h ; i++) {
        printf("%d ", g[i]);
    }
    free(g);
    
    return 0;
}