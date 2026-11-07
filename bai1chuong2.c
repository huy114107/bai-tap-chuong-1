#include <stdio.h>

int main()
{
    int n,i;
    float a[100];
    float *p;
    p=a;
    printf("So phan tu n: ");
    scanf("%d",&n);
     
    for(int i =0;i<n;i++){
        printf("phan tu thu a[%d]\n",i);
        scanf("%f",p+i);
    }
    printf("mang vua nhap la: \n");
    for(int i =0;i<n;i++){
       printf(" %.2f ",*(p+i));
    }
    return 0;
}
