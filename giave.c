// dung struct de lu thong tin ve xem phim
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct date {
    int ngay, thang, nam;
};

struct hour{
    int gio, phut;
};

struct VePhim{
    char tenphim[50];
    double giave;
    char vitri[20];
    struct date ngayxem;
    struct hour gioxem;

};

void in(struct VePhim v){
    printf("day la thong tin ve cua ban\n");
    printf("ten phim: %s\n",v.tenphim);
    printf("gia ve: %0.lf vnd\n",v.giave);
    printf("vi tri: %s\n",v.vitri);
    printf("thoi gian vao luc: %d:%d ngay %d/%d/%d\n ",v.gioxem.gio, v.gioxem.phut, v.ngayxem.ngay, v.ngayxem.thang, v.ngayxem.nam);
}

int main() {
    struct VePhim v;

    fgets(v.tenphim, sizeof(v.tenphim),stdin);
    v.tenphim[strcspn(v.tenphim,"\n") ] = '\0';

    scanf("%lf", &v.giave);
    getchar();

    scanf("%s", v.vitri);
    getchar();

    scanf("%d/%d/%d",&v.ngayxem.ngay, &v.ngayxem.thang, &v.ngayxem.nam);
    scanf("%d:%d",&v.gioxem.gio, &v.gioxem.phut);

    printf("\n cam on quy khach\n");

    in(v);

    return 0;
}
