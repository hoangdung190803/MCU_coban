// Mảng các struct sinh viên Sử dụng struct Student như trên. 
//Nhập thông tin cho n sinh viên (n ≤ 20), lưu vào mảng struct. 
//In ra danh sách sinh viên và tìm sinh viên có GPA cao nhất

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student {
    char ten[20];
    float gpa;

};

int n;
void nhap_sv(struct Student sv[],int n) {
    for (int i = 0; i < n; i++){
        printf("nhap ten sinh vien %d: ", i+1);
        getchar();
        fgets(sv[i].ten, sizeof(sv[i].ten),stdin);
        sv[i].ten[strcspn(sv[i].ten,"\n")] = '\0';

        printf("nhap GPA: ");
        scanf ("%f", &sv[i].gpa);
    }
}

void hien_sv(struct Student sv[], int n) {
    float gpamax = 0;
    int count;
    for (int i = 0; i < n; i++) {
        printf("ten: %s\nGPA: %f\n", sv[i].ten,sv[i].gpa);
        if (gpamax < sv[i].gpa){
            gpamax = sv[i].gpa;
            count = i;
        }

    }
    printf ("hoc sinh co gpa cao nhat : %s GPA: %f\n", sv[count].ten, sv[count].gpa);
}



int main() {
scanf("%d",&n);
getchar();

struct Student sv[20];
nhap_sv(sv,n);
hien_sv(sv,n);

return 0;


}
