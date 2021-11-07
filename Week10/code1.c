#include<stdio.h>

const int N=100;

int fib[N];

int getfib(int n){
    fib[1]=1,fib[2]=1;
    for(int i=3;i<=n;i++)
        fib[i]=fib[i-1]+fib[i-2];
    return fib[n];
}

int main(){

    int n;
    scanf("%d",&n);
    printf("%d\n",gitfib(n));

    return 0;
}
