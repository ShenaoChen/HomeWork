#include<stdio.h>
#include<malloc.h>

void merge(int a[],int tmpArray[],int lPos,int rPos,int rightEnd){
    int i=lPos,j=rPos,k=0;
    int numElement=rightEnd-lPos+1;

    while(i<rPos&&j<=rightEnd)
        if(a[i]<=a[j]) tmpArray[k++]=a[i++];
        else tmpArray[k++]=a[j++];

    while(i<rPos) tmpArray[k++]=a[i++];
    while(j<=rightEnd) tmpArray[k++]=a[j++];

    for(i=lPos,j=0;i<=rightEnd;i++,j++)
        a[i]=tmpArray[j];
}

void mSort(int a[],int tmpArray[],int left,int right){
    if(left==right)
        return;
    int mid=(left+right)/2;
    mSort(a,tmpArray,left,mid);
    mSort(a,tmpArray,mid+1,right);
    merge(a,tmpArray,left,mid+1,right);
}

void mergeSort(int a[],int N){
    int *tmpArray=(int *)malloc(sizeof(int)*N);
    mSort(a,tmpArray,0,N-1);
    free(tmpArray);
}

void test(){
    int a[]={-1,2,10,-3,5,7,90,17,100,38,2};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    mergeSort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main(){
    test();
    return 0;
}
