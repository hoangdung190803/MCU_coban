//Quản lý thông tin sinh viên cơ bản Định nghĩa struct Student gồm các trường: char name[50], int age, float gpa. 
//Viết chương trình nhập thông tin cho 1 sinh viên, sau đó in ra thông tin đó
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct sinhvien {
    char ten[50];
    int tuoi;
    float gpa;
};

int main() {
    struct sinhvien sv;
    fgets(sv.ten, sizeof(sv.ten), stdin);
    sv.ten[strcspn(sv.ten,"\n")] = '0';

    scanf("%d", &sv.tuoi);

    scanf("%f", &sv.gpa);
    
    printf("ten: %s\ntuoi: %d\nGPA: %f\n", sv.ten, sv.tuoi, sv.gpa);

    return 0;

}
