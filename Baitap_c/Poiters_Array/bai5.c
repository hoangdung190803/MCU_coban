// Viết hàm đảo ngược mảng (ví dụ: {1,2,3} → {3,2,1}) sử dụng hai con trỏ (đầu và cuối).
#include<stdio.h>
#include<stdlib.h>

void nhap_ham(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d ", i+1);
        scanf("%d",(arr+i));
    }
}
void ham_dao (int *arr, int n) {
    int *dau = arr; 
    int *cuoi = (arr+n-1);
    int temp;
    while (dau < cuoi) {
            temp = *dau;
            *dau = *cuoi;
            *cuoi = temp;

            dau++;
            cuoi--;
    }
        

    printf("mang sau khi dao la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",*(arr+i));
    }
}

int main() {
    int n ; // stack
    printf("nhap so phan tu cua mang: ");
    scanf("%d",&n);

    int *arr = malloc (n*sizeof(int));

    nhap_ham(arr,n);
    ham_dao(arr,n);

    free(arr);
    printf("\n");
    return 0;
} 