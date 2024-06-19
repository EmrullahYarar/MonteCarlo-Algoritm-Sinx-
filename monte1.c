 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>

 #define PI 3.14159265358979323846

 FILE * fptr;
 FILE * fptr2;
 FILE * fptr3;

 struct x_ekseni{
     double x;
 };

 struct y_ekseni{
     double y;
 };


 int main(){

     int inner, outer, didSwap, a, b, c, ctr;
     double temp,d;
     time_t t;
     srand(time(&t));

     struct x_ekseni x[10000];

     struct y_ekseni y[10000];

     srand((unsigned int)time(NULL));

     for(ctr=0; ctr<10000; ctr++){
         x[ctr].x=((double)rand()/(double)(RAND_MAX))*(PI);
     }

     for(ctr=0; ctr<10000; ctr++){
         y[ctr].y=((double)rand()/(double)(RAND_MAX))*(PI);
     }

     fptr=fopen("/home/emrullah/Genel/Monte Karlo Algaoritma/random number generates and sorts them into two text files/random.txt", "w");

     if(fptr==0){
         printf("Error! File could not be opened.\n");
         exit(1);
     }

     fprintf(fptr, "Here is the random numbers: \n");

     for(ctr=0; ctr<10000; ctr++){
         fprintf(fptr, "%f\t%f\n", x[ctr].x, y[ctr].y);
     }

     printf("\n\tRandom numbers genareted\n");

     fclose(fptr);

     fptr3=fopen("/home/emrullah/Genel/Monte Karlo Algaoritma/random number generates and sorts them into two text files/sin.txt", "w");

     if(fptr3==0){
         printf("Error! File could not be opened.\n");
         exit(1);
     }

     for(ctr=0; ctr<10000; ctr++){
         fprintf(fptr3, "%f\n", sin(x[ctr].x));
     }

     fclose(fptr3);

     a=0;

     for(ctr=0; ctr<10000; ctr++) {
         if( y[ctr].y < sin(x[ctr].x )) {
            a++;
        }
     }
     printf("\n\tNumbers under the curve: %d", a);

     d = (PI*PI)*a/10000;
     printf("\n\tThe estimate is: %f\n", d);


     b=ctr;

     for(outer=0; outer<ctr; outer++){
         didSwap=0;
         for(inner=outer; inner<b; inner++){
             if(x[inner].x<x[outer].x){
                 temp = x[inner].x;
                 x[inner].x = x[outer].x;
                 x[outer].x = temp;
                 didSwap = 1;
             }
         }
         if(didSwap == 0){
             break;

         }
     }

     c=ctr;

     for(outer=0; outer<ctr; outer++){
         didSwap=0;
         for(inner=outer; inner<c; inner++){
             if(y[inner].y<y[outer].y){
                 temp = y[inner].y;
                 y[inner].y = y[outer].y;
                 y[outer].y = temp;
                 didSwap = 1;
             }
         }
         if(didSwap == 0){
             break;

         }
     }

     fptr2=fopen("/home/emrullah/Genel/Monte Karlo Algaoritma/random number generates and sorts them into two text files/sorted_random.txt", "w");

     if(fptr2==0){
         printf("Error! File could not be opened.\n");
         exit(1);
     }

     fprintf(fptr2, "Here is the sorted random numbers: \n");

     for(ctr=0; ctr<10000; ctr++){
         fprintf(fptr2, "%f\t%f\n", x[ctr].x, y[ctr].y);
     }

     printf("\n\tRandom numbers sorted\n\n");

     fclose(fptr2);


     return 0;

 }
