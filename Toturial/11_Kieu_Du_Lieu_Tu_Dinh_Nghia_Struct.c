/*
Là kiểu dữ liệu do người dùng tự định nghĩa, kết hợp nhiều kiểu dữ liệu có sẵn lại với nhau để tạo thành 1 kiểu dữ liệu mới

Dùng để lưu cho cả 1 đối tượng gồm nhiều thông tin khác nhau của đối tượng

Cấu trúc khai báo 1 kiểu Struct
    struct tên_struct {
        dữ liệu;
    };

    để thuận tiện trong việc khai báo đối tượng cho struct trong main mà ko cần dùng từ khóa struct thì có thể khắc phục bằng 2 cách:
        dùng typedef struct tên_struct tên_thay_thế;
        dùng cấu trúc typedef struct tên_struct {
            dữ liệu;
        } tên_thay_thế;

Có thể truy cập vào từng thành phần trong struct bằng cách sử dụng toán tử . => tên_đối_tượng.tên_thành_phần

*** Kỹ thuật xử lý chuỗi nhập từ bàn phím mà chuỗi đó có dấu cách và dấu \n
    getchar();  // loại bỏ '\n' còn thừa sau scanf
    Nhập họ và tên (có thể chứa khoảng trắng) — dùng fgets
    if (fgets(tên_đối_tượng.thành_phần, sizeof(tên_đối_tượng.thành_phần), stdin) != NULL) {
        xóa ký tự newline nếu có
        tên_đối_tượng.thành_phần[strcspn(tên_đối_tượng.thành_, "\n")] = '\0';
    }

Có thế gán 2 struct cho nhau thì các thành phần trong 2 truct sẽ giống nhau

Các struct có thể lồng nhau

Có 2 cách xây dựng hàm với struct
    xây dựng hàm trả về 1 struct, tham số truyền tham trị
        kiểu_dữ_liệu_trả_về tên_hàm(tham_số) {
            khai báo đối tượng
                tên_đối_tượng đối_tượng;
            truy xuất đến đối tượng dùng .
                scanf("%d", &đối_tượng.thành_phần);
        }
    
    xây dựng hàm trả về 1 struct, tham số truyền tham chiếu
        kiểu_dữ_liệu_trả_về tên_hàm(tên_đối_tượng *đối_tượng) {
            truy xuất đến thành phần bằng ->
                scanf("%d", &đối_tượng->thành_phần);
        }

Khai báo 1 mảng struct có n phần tử có kiểu dữ liệu struct
    vẫn khởi tạo struct thông qua typedef bình thường
    trong main khai báo đối tượng và khởi tạo mảng đối tượng
        HS a[100]; // mảng a có 100 phần tử có kiểu dữ liệu struct HS
    nhập, xuất cho mảng
        for (int i = 0 ; i < 100 ; i++) {
            nhap2(&a[i]);
        }
        for (int i = 0 ; i < 100 ; i++) {
            xuat(a[i]);
        }

Bài toán tìm kiếm trong mảng có kiểu dữ liệu struct, cách làm là sẽ duyệt qua tất cả các phần tử và so sánh if, dùng hàm strcmp(2 tham số cần so sánh) để tìm kiếm
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
struct lồng nhau
struct date{
    int ngay, thang, nam;
};

typedef struct hour{
    int gio, phut, giay;
} hour;

typedef struct Ve{
    struct date Ngayxem;
    hour Gioxem;
    char tenPhim;
    double GiaVe;
}Ve;
*/

/*
typedef struct HocSinh{
    double diem;
} HS;

Xây dựng hàm nhập, xuất trả về 1 struct truyền tham trị
HS nhap1() {
    HS x;
    scanf("%d", &x.diem);
}

Xây dựng hàm trả về 1 struct truyền tham chiếu
void nhap2(HS *a) {
    scanf("%d", &a->diem);
}

Xây dựng hàm xuất với tham số là đối trượng struct
void xuat(HS x){
    printf("%d", x.diem);
}
*/

// khởi tạo 1 struct để quản lý đối tượng Sinh viên gồm các thông tin luôn đi kèm với nhau
struct Sinhvien{
    char MSSV[9];
    char HoVaTen[50];
    double GPA;
    char Lop[20];
};

// để tránh mỗi lần khai báo 1 sinh viên phỉa dùng struct Sinhvien thì có thể dùng typedef để thay thế
typedef struct Sinhvien SV;

int main() {
    // khai báo 1 sinh viên
    SV A;
    // Nhập MSSV (mảng ký tự, dùng scanf là đủ)
    scanf("%8s", A.MSSV);
    getchar();  // loại bỏ '\n' còn thừa sau scanf

    // Nhập họ và tên (có thể chứa khoảng trắng) — dùng fgets
    if (fgets(A.HoVaTen, sizeof(A.HoVaTen), stdin) != NULL) {
        // xóa ký tự newline nếu có
        A.HoVaTen[strcspn(A.HoVaTen, "\n")] = '\0';
    }

    // Nhập GPA và Lớp (Lớp không có khoảng trắng)
    scanf("%lf %19s", &A.GPA, A.Lop);

    // Xuất kết quả
    printf("%s %s %.2lf %s\n",
           A.MSSV,
           A.HoVaTen,
           A.GPA,
           A.Lop);
    // Vì MSSV và Lop là mảng nên chúng tự hạ xuống con trỏ char* – không cần '&' khi nhập với scan("%s", …)
    // GPA là biến kiểu double đơn lẻ nên cần '&' để truyền địa chỉ vào scanf("%lf", &A.GPA)
    // Sau scanf("%s", A.MSSV);, người dùng nhấn Enter → '\n' còn nằm trong bộ đệm.
    // Gọi getchar(); sẽ “ăn” ký tự '\n' thừa, để lần gọi fgets() tiếp theo không bị đọc luôn dòng rỗng.
    // scanf("%s", …) chỉ đọc đến dấu cách/tab/newline (một “từ”), gọn nhẹ khi không cần khoảng trắng.
    // fgets(buffer, size, stdin) đọc cả dòng (có khoảng trắng) và an toàn hơn nhưng cần xử lý xóa '\n'.
    
    /*
    struct lồng nhau
    Ve VeXemPhim; // khai báo đối tượng
    VeXemPhim.GiaVe;
    VeXemPhim.tenPhim;
    VeXemPhim.Ngayxem.ngay;
    VeXemPhim.Gioxem.gio;
    */

    /*
    HS a;
    nhap1(a);
    xuat(a);
    nhap2(&a);
    xuat(a);
    */
    return 0;
}