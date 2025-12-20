// Bài 1.3: Struct lồng nhau Định nghĩa struct Date (day, month, year)
// và struct Employee (name, salary, birth_date kiểu struct Date). 
// Nhập thông tin cho một nhân viên và in ra dưới dạng đẹp 
// (ví dụ: "Name: ..., Salary: ..., DOB: dd/mm/yyyy").//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Date {
    int day, month, year;
}; 

struct Employee {
    char name[50];
    double salary;
    struct Date birth_date;
};

int main () {
    struct Employee e;

    fgets(e.name, sizeof(e.name),stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    scanf ("%lf", &e.salary);
    getchar();

    scanf ("%d/%d/%d", &e.birth_date.day, &e.birth_date.month, &e.birth_date.year);
    printf("\n");

    printf("thoong tin nhan vien\n");
    printf("name: %s\n", e.name);
    printf("salary: %0.lfvnd\n", e.salary);
    printf("DOB: %d/%d/%d\n", e.birth_date.day, e.birth_date.month, e.birth_date.year);


    return 0;
}