/*
1. Cú pháp xây dựng 1 hàm
    kiểu_dữ_liệu_trả_về tên_hàm(các tham số) {
        các câu lệnh thực hiện chức năng của hàm;
        lệnh return để trả về kết quả thể hiện chức năng của hàm;
    }
    muốn sử dụng hàm thì cần phải có lời gọi hàm gọi hàm đó để sử dụng
    hàm khi gặp lệnh return nghĩa là kết thúc hàm 
    
2. biến được truyền vào hàm đgl tham số, biến được truyền vào trong lời gọi hàm được gọi là đối số

3. số lượng và kiểu dữ liệu của tham số và đối số phải giống nhau và đúng thứ tự truyền vào

4. Truyền tham trị là truyền giá trị của đối số cho tham số và trong hàm dùng giá trị của tham số để tính toán, nó ko làm thay đổi giá trị của đối số sau khi hàm kết thúc

5. Truyền tham chiếu là truyền địa chỉ của đối số cho tham số, lúc này tham số sẽ quản lý giá trị của đối số và thực hiện tính toán trong hàm, nó sẽ làm thay đổi giá trị của đối số sau khi hàm kết thúc

6. các hàm có thể gọi lại lẫn nhau, hàm được gọi phải xây dựng trước hàm gọi, nếu hàm được gọi xây dựng sau hàm gọi sẽ có lỗi

7. để khắc phục lỗi ở 6. sử dụng khai báo hàm nguyên mẫu, lúc này có thể xây dựng hàm bất kỳ chỗ nào

8. đối với hàm cần kiểm tra tính đúng sai của 1 biểu thức nên xây dựng hàm trả về 1 nếu đúng và 0 nếu sai, sau đó sẽ xử lý tính đúng sai trong hàm khác bằng if
*/

#include <stdio.h>

// xây dựng hàm in ra xin chao
void xin_chao() {
    printf("Xin chao\n");
}

// xây dựng hàm tính tổng số tự nhiên từ 1 đến n
int tong(int n) {
    int sum = 0;
    // thực hiện chức năng tính tổng của hàm
    for (int i = 0 ; i < n ; i++) {
        sum += i;
    }
    // trả về giá trị cần tính toán => kết quả mà hàm hướng tới để thực hiện chức năng của hàm
    return sum;
}

// xây dựng hàm tìm số lớn nhất trong 2 số
int max(int a, int b) {
    // lệnh thực hiện chức năng của hàm
    if (a > b)
        // lệnh trả về kết quả thể hiện chức năng của hàm 
        return a;
    else    
        // lệnh trả về kết quả thể hiện chức năng của hàm
        return b;
    printf("%d", tong(100));
}

int main() {
    int x = 50;
    int ketqua = tong(x); // lời gọi hàm, truyền giá trị the kiểu truyền tham chiếu vì mục đích chỉ cần tính tổng chứ không thay đổi giá trị của x
    printf("kết quả là: %d", ketqua);
    printf("số lớn hơn là : %d", max(10, 3)); // lời gọi hàm
    return 0;
}