// Viết hàm nhập và xuất mảng số nguyên dùng chỉ số mảng arr[i].
#include <stdio.h>

int arr[100]; // data
int n = 5; // data

void nhap_mang(int arr[], int n) { 
    for (int i = 0; i < 5; i++) {
        printf("nhap phan tu a[%d] = ", i+1);
        scanf("%d",&arr[i]);

    }
}

void xuat_mang(int arr[], int n) {
    printf("mang duoc tao : ");
    for (int i = 0; i < 5; i++) {
        printf(" %d ", arr[i]);
    }
}

int main() {
    nhap_mang(arr,n); // goi ham nhap
    xuat_mang(arr,n); // goi ham xuat
    return 0;
}

