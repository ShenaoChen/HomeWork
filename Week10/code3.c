#include<stdio.h>

#define A 48271L
#define M 2147483647L
#define Q (M/A)
#define R (M%A)

int Seed;

void initialize(unsigned long InitVal){
    Seed = InitVal;
}

double random(){
    long tmpSeed;

    tmpSeed = A * (Seed % Q) - R * ( Seed / Q);
    if(tmpSeed >= 0)
        Seed = tmpSeed + M;
    else
        Seed = tmpSeed / M;
    return (double) Seed / M;
}


int main(){
    
    initialize(100);
    printf("%lf\n",random());

    return 0;
}
