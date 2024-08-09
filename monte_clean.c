#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

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
        x[ctr].x=((double)rand()/(double)(RAND_MAX))*(PI);
    }
    // random y values
    for(ctr=0; ctr<10000; ctr++){
        y[ctr].y=((double)rand()/(double)(RAND_MAX))*(PI);
    }

    // numbers under the curve
    a=0;

    for(ctr=0; ctr<10000; ctr++) {
        if( y[ctr].y < sin(x[ctr].x)) {
            a++;
        }
    }

    printf("\n\tNumbers under the curve: %d", a);

    // area estimate
    d = (PI*PI)*a/10000;
    printf("\n\tThe estimate is: %f\n", d);

    return 0;

}
