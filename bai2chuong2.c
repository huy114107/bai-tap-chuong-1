#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m;
    float *a;
    
    printf("nhap so hang: ");
    scanf("%d",&n);
    
    printf("nhap so cot: ");
    scanf("%d",&m);
    a=(float*)malloc(n * m * sizeof(float));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("a[%d][%d]= ",i,j);
            scanf("%f",(a+i*m+j));
        }
    }
     printf("mang hai chieu vua nhap la: ");
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf(" %f ",*(a+i*m+j));
        }
    }
    free(a);
    

    return 0;
}

