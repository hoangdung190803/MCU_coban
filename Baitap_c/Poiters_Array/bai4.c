// Viết hàm tìm giá trị lớn nhất trong mảng, trả về con trỏ trỏ đến phần tử lớn nhất.
#include<stdio.h>
#include<stdlib.h>

void nhap_ham(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d ", i+1);
        scanf("%d",(arr+i));
    }
}
int* tim_max (int *arr, int n) {
    int *max = arr; // bss
    for (int i = 0; i < n; i++) {
        if (*max < *(arr+i)) {
            max = (arr+i);
            
        }
        
    }
    return max;
}

int main() {
    int n ; // stack
    printf("nhap so phan tu cua mang: ");
    scanf("%d",&n);

    int *arr = malloc (n*sizeof(int));

    nhap_ham(arr,n);
    int *max = tim_max(arr,n);
    printf(" gia tri lonw nhat cua mang la: %d \n", *max);

    free(arr);
    return 0;
} 