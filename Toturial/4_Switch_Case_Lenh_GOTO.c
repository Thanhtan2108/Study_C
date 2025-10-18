#include <stdio.h>
#include <math.h>

int main() {
    int n; scanf("%d", &n);
    switch(n) {
        case 1:
        case 2:
            printf("non");
            break;
        case 3: case 4:
            printf("già");
            break;
        case 5:
            printf("cao");
            break;
        default:
            printf("thấp");
    }

    printf("Xin chào\n");
    goto nhan;
    printf("lập trình c");
    nhan:
    printf("mọi người");

    return 0;
}