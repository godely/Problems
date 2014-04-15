#include <bits/stdc++.h>
#define db(x) cerr << #x " == " << x << "\n"
#define _ ", "

using namespace std;
#define MAXN 10000010

int cas,n,vet[MAXN];
double ans[MAXN];
double sum[MAXN];

void crivo(){
    for(int i=0;i<MAXN;i++) vet[i]=1;
    for(int i=2;i<MAXN;i+=2) vet[i]=2;
    for(long long i=3;i<MAXN;i+=2){
        if( vet[i] == 1 ) for(long long j=i*i ; j < MAXN ; j+=i ) vet[j]=i;
    }
}

int main(){
    crivo();
    sum[1]=0.0;
    ans[1]=0.0;
    for(int i=2;i<MAXN;i++){
        if ( vet[i]==1 || vet[i] == i ) ans[i]=log10(i);
        else ans[i]=(ans[i/vet[i]]+log10(vet[i]));
        sum[i]=sum[i-1]+ans[i];
    }
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        printf("%d\n",n==1?1:int(ceil(sum[n])));
    }
    return 0;
}
