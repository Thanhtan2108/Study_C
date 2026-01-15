/*
1. Các kiểu dữ liệu trong C:
int : 4 byte : lưu số nguyên : %d
unsigned int : 4 byte : lưu số nguyên ko âm : %u
long long(long long int) : 8 byte : lưu số nguyên lớn hơn int : %lld
float: 4 byte : lưu số thực : %f
double : 8 byte : lưu số thực : %lf
char : 1 byte : lưu ký tự : %c
uint8_t : 8 bit: lưu số nguyên không âm 8 bit
uint16_t : 16 bit : lưu số nguyên không âm 16 bit
uint32_t : 32 bit : lưu số nguyên không âm 32 bit
đặc tả số HEX : %X

2. Khai báo biến và quy tắc đặt tên biến
Quy tắc đặt tên biến:
    Chỉ được chứa chữ cái, chữ số, dấu gạch dưới
    Ký tự tên bắt đầu không được là chữ số
    Tên biến không được trùng với các từ khóa trong C
    Ko nên đặt tên biến dài quá 31 ký tự
Cú pháp khai báo biến:
    Kiểu_dữ_liệu Tên_biến;
Có thể khai báo nhiều biến trên cùng 1 dòng nếu chúng có dùng chung 1 kiểu dữ liệu, các biến cách nhau bằng dấu ,
Có thể khởi tạo giá trị cho biến ngay khi khai báo biến qua phép gán =

3. Vào ra trong C
Xuất ra màn hình bằng hàm printf();
    In chuỗi bằng printf("Chuỗi");
    In giá trị biến bằng printf("đặc tả của biến", biến);
    In ra số thực lấy n số thập phân bằng printf("%.nf/lf", biến);
    In ra giá trị của nhiều biến cùng 1 lúc bằng printf("đặc_tả_1 đặt_tả_2 đặt_tả_3", biến_1, biến_2, biến_3);
    In ra chuỗi và giá trị của biến bằng printf("chuỗi đặt_tả_của_biến", tên_biến);

Nhập vào từ bàn phím bằng hàm scanf();
    Nhập giá trị cho biến bằng scanf("đặt tả của biến", &tên biến);
    Nhập giá trị cho nhiều biến cùng lúc bằng scanf("đặt_tả_1 đặt_tả_2 đặt_tả_3", &biến_1, &biến_2, &biến_3);
    Lưu ý đặt tả cuối cùng không được có dấu cách trước "

    **Xử lý ký tự và chuỗi có khoảng trắng trong C:**
    - Hàm getchar():
        • Dùng để nhập 1 ký tự duy nhất từ bàn phím.  
        • Mỗi lần gọi getchar() sẽ đọc 1 ký tự trong bộ đệm stdin (bao gồm cả ký tự '\n' khi nhấn Enter).  
        • Khi nhập một ký tự và nhấn Enter, getchar() sẽ đọc ký tự đầu tiên, còn '\n' vẫn nằm trong bộ đệm.  
        • Vì vậy, nếu sau getchar() có lệnh nhập chuỗi, cần đọc bỏ '\n' thừa bằng getchar() hoặc vòng lặp:
              while (getchar() != '\n');
    
    - Hàm fgets():
        • Dùng để nhập chuỗi có khoảng trắng (ví dụ: "Xin chào Việt Nam").  
        • Cú pháp: fgets(tên_mảng, kích_thước, stdin);  
        • fgets() đọc cả ký tự cách và dừng khi gặp '\n' hoặc hết kích thước - 1.  
        • fgets() **lưu luôn ký tự '\n'** vào cuối chuỗi → cần loại bỏ nếu không muốn xuống dòng khi in ra:
              str[strcspn(str, "\n")] = '\0';
        • Khác với scanf("%s", ...) chỉ đọc đến khoảng trắng đầu tiên, fgets() đọc cả dòng.  
        • Nếu fgets() nằm sau một scanf() hoặc getchar(), cần đảm bảo xóa '\n' còn sót trong bộ đệm trước đó.

    Ví dụ:
        char d;
        char str[50];
        printf("Nhập ký tự: ");
        d = getchar();              // nhập 1 ký tự, ví dụ: A
        while (getchar() != '\n');  // loại bỏ '\n' thừa
        printf("Nhập chuỗi có khoảng trắng: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // xóa '\n' ở cuối chuỗi
        printf("Ký tự: %c\n", d);
        printf("Chuỗi: %s\n", str);


4. Ký tự đặc biệt
Ký tự xuống dòng: \n
Ký tự tab: \t
*/

#include <stdio.h>

int main() {
    int a, b = 0;
    float c;
    char d;
    char str[100]; // mảng để chứa chuỗi có khoảng trắng

    printf("Nhập giá trị cho a, b, c: ");
    scanf("%d %d %f", &a, &b, &c);
    //'5' ' ' '1' '0' ' ' '3' '.' '5' '\n'

    printf("Nhập giá trị cho d: ");
    getchar();          // bỏ '\n' còn lại sau scanf
    scanf("%c", &d);    // nhập 1 ký tự
    // 'c' ' ' '\n'

    printf("Nhập một chuỗi có khoảng trắng: ");
    getchar();          // bỏ '\n' còn lại sau khi nhập ký tự d
    fgets(str, sizeof(str), stdin); // đọc cả dòng, kể cả khoảng trắng

    printf("\nGiá trị của a: %d b: %d c: %.2f d: %c\n", a, b, c, d);
    printf("Chuỗi bạn vừa nhập: %s\n", str);

    return 0;
}
