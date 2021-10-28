#include<stdio.h>

//希尔增量
void shellSort1(int a[],int n){
    int i,j,increment,tmp;
    for(increment=n/2;increment>0;increment/=2){
        for(i=increment;i<n;i++){
            tmp=a[i];
            for(j=i;j>=increment;j-=increment){
                if(a[j-increment]>tmp)
                    a[j]=a[j-increment];
                else 
                    break;
            }
            a[j]=tmp;
        }
    }
}

//Hibbard增量
void shellSort2(int a[],int n){
    int i,j,tmp;
    int increment=1;
    while(increment*increment<n)
        increment*=2;
    for(increment--;increment>0;increment=(increment+1)/2-1){
        for(i=increment;i<n;i++){
            tmp=a[i];
            for(j=i;j>=increment;j-=increment){
                if(a[j-increment]>tmp)
                    a[j]=a[j-increment];
                else 
                    break;
            }
            a[j]=tmp;
        }
    }
}

void test(){
    int a[]={-1,2,10,-3,5,7,90,17,100,38,2};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    shellSort1(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    shellSort2(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(){
    test();
    return 0;
}
