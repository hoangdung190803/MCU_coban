//  Viết hàm tính tổng mảng sử dụng con trỏ, duyệt mảng bằng cách tăng con trỏ.
#include<stdio.h>
#include<stdlib.h>

void nhap_ham(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d ", i+1);
        scanf("%d",(arr+i));
    }
}
void tinh_tong(int *arr, int n) {
    int sum = 0; // bss
    for (int i = 0; i < n; i++) {
        sum += *arr;
        arr++;
        
    }
    printf("tong gia tri cua mang la: %d ", sum);
    
}

int main() {
    int n ; // stack
    printf("nhap so phan tu cua mang: ");
    scanf("%d",&n);
    int *arr = malloc (n*sizeof(int));

    nhap_ham(arr,n);
    tinh_tong(arr,n);

    free(arr);
    return 0;
} 