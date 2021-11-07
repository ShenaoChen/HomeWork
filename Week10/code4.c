typedef long long ll;

ll pow(ll a,ll n){
    if(n==0)
        return 1;
    ll tmp=pow(a,n/2);
    if(n%2==0)
        return tmp*tmp;
    else
        return tmp*tmp*a;
}

int main(){
  int a,n;
  
  scanf("%d%d",&a,&n);
  printf("%d\n",pow(a,n));
  
  return 0;
}
