//I write this code for hobby purposes. Whoever wants to use it can use.
//Simple Monte Carlo Algorithm to estimate the values of sinx function.
//It gives random numbers to x and y, then it compares y and sinx values.
//After that it estimates the area for given numbers.
//If you are using Linux sinx library sometimes gives error,so use "gcc monte1.c -o monte1 -lm" to compile and use "./monte1" to run.

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

    //You can adjust the x and y values by adjusting given random numbers.
    // random x values
    for(ctr=0; ctr<10000; ctr++){
        x[ctr].x=((double)rand()/(double)(RAND_MAX))*(PI);
    }

    //random y values
    for(ctr=0; ctr<10000; ctr++){
        y[ctr].y=((double)rand()/(double)(RAND_MAX))*(PI);
    }

    //If you want to see collected x and y values active here.
    /*
    fptr=fopen( Your Directiory , "w");

    if(fptr==0){
        printf("Error! File could not be opened.\n");
        exit(1);
    }

    fprintf(fptr, "Here is the random numbers: \n");

    // Writes x and y values at same line with one tab space
    for(ctr=0; ctr<10000; ctr++){
         fprintf(fptr, "%f\t%f\n", x[ctr].x, y[ctr].y);
    }

    printf("\n\tRandom numbers genareted\n");

    fclose(fptr);
    */

    //If you want to see collected sinx active here.
    /*
    fptr2=fopen( Your Directiory, "w");

    if(fptr2==0){
        printf("Error! File could not be opened.\n");
        exit(1);
    }

    for(ctr=0; ctr<10000; ctr++){
        fprintf(fptr2, "%f\n", sin(x[ctr].x));
    }

    fclose(fptr2);
    */

    //Counts the random y numbers less than sinx.
    a=0;

    for(ctr=0; ctr<10000; ctr++) {
        if( y[ctr].y < sin(x[ctr].x )) {
            a++;
        }
    }
    printf("\n\tNumbers under the curve: %d", a);

    //Area estimated
    // !!! If you change the random value interval of x and y do not forget to change area intervals.
    d = (PI*PI)*a/10000;
    printf("\n\tThe estimate is: %f\n", d);

    //Here sorts the x and y values and writes them at sime line with one tab space.
    //The number of random numbers affects the sorting time. I do not recommend working with Python if you working with 10.000 numbers and above.
    /*
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

    fptr3=fopen("/home/emrullah/Genel/Monte Karlo Algaoritma/random number generates and sorts them into two text files/sorted_random.txt", "w");

    if(fptr3==0){
        printf("Error! File could not be opened.\n");
        exit(1);
    }

    fprintf(fptr3, "Here is the sorted random numbers: \n");

    for(ctr=0; ctr<10000; ctr++){
        fprintf(fptr3, "%f\t%f\n", x[ctr].x, y[ctr].y);
    }

    printf("\n\tRandom numbers sorted\n\n");

    fclose(fptr3);
    */

//
    return 0;

}
