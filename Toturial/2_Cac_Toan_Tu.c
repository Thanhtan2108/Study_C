/*
Các toán tử trong C
Toán tử 2 ngôi:
    + : cộng 2 số
    - : trừ 2 số
    * : nhân 2 số
    / : chia lấy thương 2 số
    % : chia lấy dư 2 số

Toán tử gán
    = : gán
    += : = +
    -+ : = -
    *= = &
    /= : = /
    %= : = %

Toán tử 1 ngôi
    ++ : tăng 1 đơn vị
    -- : giảm 1 đơn vị

    a++ : lấy a thực hiện phép tính xong rồi mới tăng a lên thêm 1 đơn vị
    ++a : tăng a lên 1 đơn vị trước khi thực hiện phép tính rồi mới đi thực hiện tính toán

Toán tử so sánh
    == : so sánh bằng
    <= : bé hơn hoặc bằng
    < : bé hơn
    >= : lớn hơn hoặc bằng
    > : lớn
    != : so sánh khác

Toán tử logic
    AND : &&
    OR : ||
    NOT : !

Các hàm toán học hay dùng
    sprt(x) : Hàm căn bậc 2 : tính căn bậc 2 của x và trả về double
    pow(x, y) : Hàm tính x^y
*/

#include <stdio.h>
#include <math.h>

int main() {
    int a = 20, b = 30;
    int tong = a + b;
    int hieu = b - a;
    int tich = a * b;
    int thuong = b / a;
    float thuong1 = (float)b / a;
    float thuong2 = 1.0 * b / a;
    int du = b % a;
    printf("Kết quả của tong: %d, hieu: %d, tích: %.d, thương: %.d, thương số thực: %.2f %.2f, dư: %d", tong, hieu, tich, thuong, thuong1, thuong2, du);
    printf("\n");

    int x = 100; // y -> x -> 101 -> z -> 102
    int y = x++; // x -> 100 -> y -> 101 -> x
    int z = ++x; // x -> 101 -> 102 -> z -> x
    printf("Giá trị của biến x: %d ", x);
    printf("giá trị của biến y: %d ", y);
    printf("Giá trị của biến z: %d ", z);

    a += b;
    a -+ b;
    a *= b;
    a /= b;
    a %= b;

    return 0;
}