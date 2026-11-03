# bai-tap-chuong-1
bai 1
#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c,x1,x2,delta,x;
   scanf("%f %f %f",&a,&b,&c);
   if(a==0){
       if(b==0){
           if(c==0){
               printf("PT vo so nghiem");
           }
           else{
               printf("PT vo nghiem");
           }
       }
       else{
           x=-c/b;
           printf("%.2f",x);
       }
   }else{
      delta=b*b-4*a*c;
      if(delta<0){
          printf("PT vo nghiem");
      }else{
          if(delta==0){
            x=-b/2*a;
            printf("%.2f",x);
          }
          else{
              x1=(-b+sqrt(delta))/(2*a);
              x2=(-b-sqrt(delta))/(2*a);
              printf("x1=%.2f\n",x1);
              printf("x2=%.2f\n",x2);
      }
   }
   }
    return 0;
}
