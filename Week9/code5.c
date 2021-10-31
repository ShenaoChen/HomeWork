#include<stdio.h>
#define Cutoff 3

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void insertionSort(int a[],int N){
    int i,j,tmp;
    for(int i=1;i<N-1;i++){
        tmp=a[i];
        for(j=i;j>0;j--){
            if(a[j-1]>tmp)
                a[j]=a[j-1];
        }
        a[j]=tmp;
    }
}

int median3(int a[],int left,int right){
    int mid=left+right>>1;
    if(a[left]>a[mid])
        swap(&a[left],&a[mid]);
    if(a[left]>a[right])
        swap(&a[left],&a[right]);
    if(a[mid]>a[right])
        swap(&a[mid],&a[right]);
    swap(&a[mid],&a[right-1]);
    return a[right-1];
}

void qSort(int a[],int left,int right){
    int i,j,pivot=median3(a,left,right);
    if(left+Cutoff<=right){
        i=left,j=right-1;
        while(i<j){
            while(a[++i]<pivot);
            while(a[--j]>pivot);
            if(i<j)
                swap(&a[i],&a[j]);
        }
        swap(&a[i],&a[right-1]);
        qSort(a,left,i-1);
        qSort(a,i+1,right);
    }
    else
        insertionSort(a+left,right-left+1);
}

void quickSort(int a[],int N){
    qSort(a,0,N-1);
}

void test(){
    int a[]={-1,2,10,-3,5,7,90,17,100,38,2};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    quickSort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main(){
    test();
    return 0;
}
