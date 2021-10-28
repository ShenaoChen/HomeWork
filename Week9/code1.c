#include<stdio.h>

void insertionSort(int a[],int n){
    int i,j,tmp;
    for(i=1;i<n;i++){
        tmp=a[i];
        for(j=i;j>0&&a[j-1]>tmp;j--)
            a[j]=a[j-1];
        a[j]=tmp;
    }
}

void test(){
    int a[]={-1,2,10,-3,5,7,90,17,100,38,2};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    insertionSort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(){
    test();
    return 0;
}
