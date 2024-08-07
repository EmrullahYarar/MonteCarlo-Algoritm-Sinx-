 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>

 struct x_ekseni{
     double x;
 };

 struct y_ekseni{
     double y;
 };

 int main(){

     int a, ctr;
     double temp,d;
     time_t t;
     srand(time(&t));

     struct x_ekseni x[10000];

     struct y_ekseni y[10000];

     srand((unsigned int)time(NULL));

     // random x values
     for(ctr=0; ctr<10000; ctr++){
         x[ctr].x=((double)rand()/(double)(RAND_MAX))*(2);
     }
     // random y values
     for(ctr=0; ctr<10000; ctr++){
         y[ctr].y=((double)rand()/(double)(RAND_MAX))*(4);
     }
     // numbers under the curve
     a=0;

     for(ctr=0; ctr<10000; ctr++) {
         if( y[ctr].y < ((x[ctr].x)*x[ctr].x)) {
             a++;
         }
     }
     printf("\n\tNumbers under the curve: %d", a);
     // area estimate
     d = (8)*a/10000;
     printf("\n\tThe estimate is: %f\n", d);

     return 0;

 }
