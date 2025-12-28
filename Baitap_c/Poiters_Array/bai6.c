#include<stdio.h>
#include<stdlib.h>

void* tim_max(int *arr, int n){
    int *max = arr;
    for (int i = 0; i < n; i++) {
        if (*max < *(arr+i)){
            max = (arr+i);
        }
    }
    return max;
}

int main(){
    int *arr = NULL;
    int n = 0;
    int x;
    
    printf("nhap cac phan tu cau mang: ");
    while(scanf("%d",&x) == 1) // voi moi 1 vong lap nhap 1 phan tu trong mang
                               // neu phan tu ko phai so nguywn thi dung vong while ctrl+d ket thuc nhap mang
    {
        int *ptr = realloc(arr, (n+1)*sizeof(int));
        if (ptr == NULL) {
            free(arr);   // giai phong arr cu
            return 1;
        }
        arr = ptr;
        arr[n++] = x;
    }
    int *maxvalue = tim_max(arr,n);
    printf("phan tu lon nhat cua mang vua nhap la: %d\n",*maxvalue);
    free(arr);
    return 0;
}
