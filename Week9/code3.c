#include<stdio.h>
#define leftChild(i) (2*(i)+1)

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void percDown(int a[],int i,int N){
    int child;
    int tmp;

    for(tmp=a[i];leftChild(i)<N;i=child){
        child=leftChild(i);
        if(child!=N-1&&a[child+1]>a[child])
            child++;
        if(tmp<a[child])
            a[i]=a[child];
        else
            break;
    }
    a[i]=tmp;
}

void heapSort(int a[],int N){
    for(int i=N/2;i>=0;i--)
        percDown(a,i,N);
    for(int i=N-1;i>0;i--){
        swap(&a[i],&a[0]);
        percDown(a,0,i);
    }   
}

void test(){
    int a[]={-1,2,10,-3,5,7,90,17,100,38,2};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    heapSort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main(){
    test();
    return 0;
}
