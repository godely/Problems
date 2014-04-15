#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for( int a = b ; a < c ; a++ )
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
#define MM 100010
#define PB push_back
#define mp make_pair

int a,b;
long long ans,n;
vector<int> mat[MM];
bool mark[MM];
int cont;

void dfs(int v){
    if(mark[v]) return;
    mark[v]=true;
    cont++;
    for(int i=0;i<mat[v].size();i++)
        dfs(mat[v][i]);
    ans+=(n-cont);
}

int main(){
    int casos,cas=1;
    scanf("%d",&casos);
    while(casos--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) mat[i].clear();
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            mat[a].PB(b);
        }
        cont=0;
        memset(mark,false,sizeof(mark));
        ans=0;
        dfs(1);
        printf("Case %d: %lld %lld\n",cas++,n-1,ans);
    }
    return 0;
}
