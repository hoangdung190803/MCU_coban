// Viết lại Bài 1 nhưng dùng con trỏ *(arr + i) để truy cập phần tử.
#include <stdio.h>
#include <stdlib.h>

void nhap_mang(int *arr, int n) {
for (int i = 0; i < n; i++) {
    printf("nhap phan tu arr[%d] ", i+1);
    scanf("%d",(arr + i));

    }
}

void xuat_mang(int *arr, int n) {
    printf("mang duoc xuat ra  ");
    for (int i = 0; i < n; i++) {
    printf("%d ", *(arr + i));

    }


}

int main() {

int n ; // stack
printf("nhap so phan tu cua mang ");
scanf("%d",&n);

int *arr = malloc(n* sizeof(int)); // tao 1 con tro tro toi n phan tu tren heap

nhap_mang(arr, n); //goi ham nhap
xuat_mang(arr, n); //goi ham xuat

printf("\n");
free(arr);
return 0;
}
