#include<stdio.h>
#define numSets 100

typedef int disjSet[numSets+1];
typedef int setType;

void init(disjSet S){
    for(int i=numSets;i>0;i--)
        S[i]=0;
}

setType find(int x,disjSet S){
    if(S[x]<=0)
        return x;
    else 
        return S[x]=find(S[x],S);
}

void setUnion(disjSet S,setType root1,setType root2){
    if(S[root2]<S[root1])
        S[root1]=root2;
    else{
        if(S[root1]==S[root2])
            S[root1]--;
        S[root2]=root1;
    }
}

void test(){
    disjSet S;
    init(S);
    printf("%d\n",find(2,S));
    setUnion(S,1,2);
    printf("%d\n",find(2,S));    
}

int main(){
    test();
    return 0;
}
