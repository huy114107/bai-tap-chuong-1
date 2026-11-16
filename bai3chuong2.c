
#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    char hoten[50];
    char ma[20];
    float diem1, diem2, diem3;
};

int main()
{
    int n;
    struct SinhVien *a;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    a = (struct SinhVien*)malloc(n * sizeof(struct SinhVien));

    if(a == NULL){
        printf("Khong the cap phat bo nho!");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("\nNhap sinh vien thu %d:\n", i+1);

        printf("Ho ten: ");
        scanf(" %49[^\n]", (a+i)->hoten);

        printf("Ma sinh vien: ");
        scanf(" %19s", (a+i)->ma);

        printf("Diem 1: ");
        scanf("%f", &(a+i)->diem1);

        printf("Diem 2: ");
        scanf("%f", &(a+i)->diem2);

        printf("Diem 3: ");
        scanf("%f", &(a+i)->diem3);
    }
    printf("\nDANH SACH SINH VIEN\n");

    for(int i = 0; i < n; i++){
        printf("\nSinh vien thu %d:\n", i+1);

        printf("Ho ten: %s\n", (a+i)->hoten);
        printf("Ma sinh vien: %s\n", (a+i)->ma);
        printf("Diem 1: %.2f\n", (a+i)->diem1);
        printf("Diem 2: %.2f\n", (a+i)->diem2);
        printf("Diem 3: %.2f\n", (a+i)->diem3);
    }
    free(a);

    return 0;
}
