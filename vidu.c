// tao 1 struct sinh vien va truy cap vao do
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct sinhvien {
    char ma[20];
    char ten[50];
    double gpa;
    char truong[30];
};

typedef struct sinhvien sv;

int main() {
    sv a;
    // su dung toan tu dau cham dot operator
    scanf("%s", a.ma);
    getchar();

    fgets(a.ten, sizeof(a.ten),stdin);
    a.ten[strcspn(a.ten,"\n")] = '\0';

    scanf("%lf",&a.gpa);
    getchar();

    fgets(a.truong, sizeof(a.truong), stdin);
    a.truong[strcspn(a.truong, "\n")] = '\0';

    printf(" ma sv: %s\n ten: %s\n gpa: %.2f\n truong: %s\n", a.ma, a.ten, a.gpa, a.truong);
    return 0;
}
