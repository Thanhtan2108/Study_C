/*
1️⃣ Lý thuyết cơ bản
Con trỏ hàm là gì?
Định nghĩa: Khi viết 1 hàm bất kỳ thì sẽ có địa chỉ hàm, và cứ có địa chỉ thì có thể dùng con trỏ để quản lý
            Con trỏ hàm là một biến dùng để lưu trữ địa chỉ của một hàm. Địa chỉ của hàm là địa chỉ bắt đầu của hàm đó
Nhờ nó, bạn có thể:
    Gọi hàm thông qua con trỏ giống như gọi hàm bình thường.
    Truyền hàm làm tham số cho hàm khác (callback).
    Lưu trữ nhiều hàm trong một mảng để chọn và gọi động (runtime).
Nói ngắn gọn: Con trỏ hàm biến một hàm thành dữ liệu, giúp bạn truyền và xử lý "hàm" như một biến.

2️⃣ Chức năng & Ví dụ minh họa
✅ Chức năng 1: Gọi lại hàm (Callback)
Vấn đề khi không dùng con trỏ hàm:
Một hàm tổng quát (thucHien) không thể thay đổi logic tính toán bên trong nếu không sửa code hoặc viết thêm nhiều phiên bản.

Ví dụ:

🔹 (1) Không dùng con trỏ hàm
#include <stdio.h>

int cong(int a, int b) { return a + b; }
int nhan(int a, int b) { return a * b; }

Hàm thực hiện cộng
void thucHienCong(int x, int y) {
    printf("Kết quả: %d\n", cong(x, y));
}

Hàm thực hiện nhân
void thucHienNhan(int x, int y) {
    printf("Kết quả: %d\n", nhan(x, y));
}

int main() {
    thucHienCong(5, 3);
    thucHienNhan(5, 3);
    return 0;
}
Kết quả:
Kết quả: 8
Kết quả: 15
⚠️ Nhược điểm: phải viết 2 hàm gần như giống nhau, chỉ khác lời gọi cong hoặc nhan.

🔹 (2) Dùng con trỏ hàm (callback)
#include <stdio.h>

int cong(int a, int b) { return a + b; }
int nhan(int a, int b) { return a * b; }

Hàm tổng quát nhận hàm xử lý
void thucHien(int x, int y, int (*pheptoan)(int,int)) {
    printf("Kết quả: %d\n", pheptoan(x, y));
}

int main() {
    thucHien(5, 3, cong);
    thucHien(5, 3, nhan);
    return 0;
}
Kết quả:
Kết quả: 8
Kết quả: 15
✅ Ưu điểm: chỉ cần 1 hàm duy nhất, linh hoạt nhận hàm khác nhau.


✅ Chức năng 2: Thay đổi hành vi của chương trình tại runtime
Vấn đề: Nếu bạn chỉ dùng lời gọi trực tiếp, hàm cần gọi cố định ngay từ khi biên dịch.
Con trỏ hàm cho phép bạn chọn hàm khi chương trình đang chạy.

Ví dụ:

🔹 (1) Không dùng con trỏ hàm
#include <stdio.h>

int cong(int a, int b) { return a + b; }
int nhan(int a, int b) { return a * b; }

int main() {
    int x=5, y=3, kq;
    char op;

    printf("Nhập phép tính (+ hoặc *): ");
    scanf(" %c", &op);

    if (op == '+') kq = cong(x,y);
    else kq = nhan(x,y);

    printf("Kết quả: %d\n", kq);
    return 0;
}
Test:
Nhập + → 8
Nhập * → 15

🔹 (2) Dùng con trỏ hàm
#include <stdio.h>

int cong(int a, int b) { return a + b; }
int nhan(int a, int b) { return a * b; }

int main() {
    int x=5, y=3;
    char op;
    int (*operation)(int,int);

    printf("Nhập phép tính (+ hoặc *): ");
    scanf(" %c", &op);

    if (op == '+') operation = cong;
    else operation = nhan;

    printf("Kết quả: %d\n", operation(x, y));
    return 0;
}
Test:
Nhập + → 8
Nhập * → 15
✅ Ưu điểm: Khi code phức tạp hơn, bạn chỉ cần 1 dòng gọi operation(), không phải lặp if-else ở nhiều nơi.


✅ Chức năng 3: Mảng con trỏ hàm (Function Table)
Vấn đề: Khi có nhiều hàm khác nhau, bạn sẽ có switch-case hoặc if-else dài dòng.

Ví dụ

🔹 (1) Không dùng con trỏ hàm
#include <stdio.h>

int cong(int a, int b){return a+b;}
int tru(int a, int b){return a-b;}
int nhan(int a, int b){return a*b;}
int chia(int a, int b){return b? a/b : 0;}

int main(){
    int x=10, y=5, kq;
    char op;
    printf("Nhập phép tính (+,-,*,/): ");
    scanf(" %c", &op);

    if(op=='+') kq=cong(x,y);
    else if(op=='-') kq=tru(x,y);
    else if(op=='*') kq=nhan(x,y);
    else if(op=='/') kq=chia(x,y);
    else {printf("Sai phép tính!\n"); return 0;}

    printf("Kết quả: %d\n", kq);
    return 0;
}

🔹 (2) Dùng mảng con trỏ hàm
#include <stdio.h>

int cong(int a,int b){return a+b;}
int tru(int a,int b){return a-b;}
int nhan(int a,int b){return a*b;}
int chia(int a,int b){return b? a/b : 0;}

int main(){
    int x=10,y=5;
    char ops[] = {'+','-','*','/'};
    int (*functions[])(int,int) = {cong,tru,nhan,chia};

    char op;
    printf("Nhập phép tính (+,-,*,/): ");
    scanf(" %c", &op);

    for(int i=0;i<4;i++){
        if(op==ops[i]){
            printf("Kết quả: %d\n", functions[i](x,y));
            return 0;
        }
    }
    printf("Sai phép tính!\n");
    return 0;
}
Kết quả:
Nhập + → 15
Nhập / → 2

✅ Ưu điểm: Dễ mở rộng thêm hàm chỉ bằng thêm vào mảng, không cần sửa if-else.
            Không cần viết thêm nhiều câu if-else. 
            Chỉ cần thêm một phần tử vào mảng để mở rộng. 
            Đây là cách tạo menu động, bảng lệnh trong các ứng dụng lớn.


✅ Chức năng 4: Mô phỏng đa hình (Polymorphism) trong C
Trong C++ hoặc Java, bạn có thể viết class cha và override hàm ở class con.
Trong C, bạn làm điều tương tự bằng struct chứa con trỏ hàm.

Ví dụ:

🔹 (1) Không dùng con trỏ hàm (dùng struct + if-else)
#include <stdio.h>
#include <string.h>

/ Định nghĩa struct Animal chỉ lưu tên loại
typedef struct {
    char type[10];  // Lưu loại động vật (dog, cat, ...)
} Animal;

/ Các hàm hành vi
void dogSpeak() { printf("Gâu gâu!\n"); }
void catSpeak() { printf("Meo meo!\n"); }
void crowSpeak() { printf("Quạ quạ!\n"); }  // 🆕 Thêm hành vi chim quạ

/ Hàm kiểm tra và gọi hành vi phù hợp
void speak(Animal a) {
    if (strcmp(a.type, "dog") == 0)
        dogSpeak();
    else if (strcmp(a.type, "cat") == 0)
        catSpeak();
    else if (strcmp(a.type, "crow") == 0)   // 🆕 Thêm điều kiện mới
        crowSpeak();
    else
        printf("Không biết loại!\n");
}

int main() {
    / Khai báo từng đối tượng động vật
    Animal dog;
    strcpy(dog.type, "dog");  // Gán loại "dog" cho struct

    Animal cat;
    strcpy(cat.type, "cat");  // Gán loại "cat" cho struct

    Animal crow;                          // 🆕 Tạo đối tượng chim quạ
    strcpy(crow.type, "crow");

    / Gọi hành vi
    speak(dog);
    speak(cat);
    speak(crow);                          // 🆕 Gọi hành vi mới

    return 0;
}
Kết quả:
Gâu gâu!
Meo meo!
⚠️ Nhược điểm: Hàm speak() phải kiểm tra if-else cho từng loại động vật.
Nếu có thêm loài mới(crow), phải sửa speak() thêm nhiều if-else.

🔹 (2) Dùng con trỏ hàm trong struct (đa hình đúng nghĩa)
#include <stdio.h>

/ Định nghĩa struct Animal có con trỏ hàm speak
typedef struct {
    void (*speak)();  // Con trỏ hàm trỏ đến hành vi "nói"
} Animal;

/ Các hàm hành vi
void dogSpeak() { printf("Gâu gâu!\n"); }
void catSpeak() { printf("Meo meo!\n"); }
void crowSpeak() { printf("Quạ quạ!\n"); }  // 🆕 Thêm hành vi chim quạ

int main() {
    / Khai báo từng đối tượng động vật
    Animal dog;
    dog.speak = dogSpeak;  // Gán hàm dogSpeak cho con trỏ speak

    Animal cat;
    cat.speak = catSpeak;  // Gán hàm catSpeak cho con trỏ speak

    / Khai báo đối tượng quạ 🆕
    Animal crow;
    crow.speak = crowSpeak;   // Chỉ cần gán hàm mới, không sửa code chung

    / Gọi hành vi qua con trỏ hàm
    dog.speak();
    cat.speak();
    crow.speak();             // 🆕 Gọi hành vi chim quạ

    return 0;
}
Kết quả:
Gâu gâu!
Meo meo!
✅ Ưu điểm: Không cần if-else để chọn hàm, mỗi đối tượng tự mang hành vi riêng nhờ con trỏ hàm.
Thêm loại mới (ví dụ crowSpeak) chỉ cần tạo một Animal cow mà không cần sửa code chung, ko cần if-else
Trong lập trình hệ điều hành, plugin, driver... cách này rất mạnh.


3️⃣ Khi nào KHÔNG cần con trỏ hàm
Khi chỉ có 1 hoặc 2 hàm cố định, không cần sự linh hoạt → gọi trực tiếp là tối ưu.
Con trỏ hàm không giúp tăng tốc hay tiết kiệm bộ nhớ, nó chỉ giúp linh hoạt và tái sử dụng code.

Cách định nghĩa 1 con trỏ hàm
    typedef kiểu_dữ_liệu_cùng_với_kiểu_dữ_liệu_hàm_trả_về (*tên_con_trỏ) {kiểu_dữ_liệu_các_tham_số_của_hàm_trỏ_tới};

Cách khai báo 1 con trỏ hàm
    tên_con_trỏ_ tên_con_trỏ_hàm; // xem tên_con_trỏ_hàm như 1 biến

Cách khai báo Mảng con trỏ hàm
    kiểu_dữ_liệu_cùng_kiểu_dữ_liệu_hàm_trả_về (*tên_mảng_con_trỏ_hàm[có_thể_truyền_số_lượng_hàm_hoặc_ko])(các_kiểu_dữ_liệu_tham_số_hàm) = {các_hàm_truyền_vào_mảng_con_trỏ_để_quản_lý};

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // thư viện kiểu dữ liệu bit thường dùng trong nhúng

#define cnt 3

void reg1() {
    printf("reg1\n");
}

void reg2() {
    printf("reg2\n");
}

void reg3() {
    printf("reg3\n");
}

// định nghĩa con trỏ hàm
void (*mfunction[])() = {reg1, reg2, reg3};

int main() {
    for (int i = 0 ; i < cnt ; i++) {
        mfunction[i]();
    }

    /*
    Nếu không dùng mảng con trỏ hàm như trên, khi muốn in ra các hàm reg1, reg2, reg3
    thì cần lời gọi hàm
    reg1();
    reg2();
    reg3();
    => điều này làm cho chương trình cứng nhắc và khó mở rộng khi có phát triển thêm các hàm khác, 
    lúc này cần phải bổ sung vào trong main thì ko khuyến khích vì có thể gây lỗi giải thuật của chương trình
    */
    return 0;
}   
