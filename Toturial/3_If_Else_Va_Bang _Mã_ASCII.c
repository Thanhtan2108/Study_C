/*
Cấu trúc If Else
    if(condition) {

    } else {
        
    }


    if() {
        if() {
        
        }
    }


    if() {

    } else if() {
    
    } else if() {
    
    } else {
    
    }

bảng mã ASCII
A - Z : 65 - 90
a - z : 97 - 122
0 - 9 : 48 - 57

*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if((n >= 50) && (n <= 100))
        printf("x thoa");
    else
        printf("khong thoa");

    if(n >= 50) {
        if(n <= 100) {
            printf("x lam em");
        }
    }

    return 0;
}