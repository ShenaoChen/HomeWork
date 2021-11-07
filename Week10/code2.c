#include<stdio.h>

const int N=100;
int g[N][N];

void floyd(int n){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main(){

    int n,m;
    int a,b,w;

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=w;
        g[b][a]=w;
    }

    floyd(n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",g[i][j]);
        printf("\n");
    }
    
    return 0;
}
