#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define LL long long

using namespace std;

int add[30], most, sum;
char str[1111];
int main() {
    int T, R, C, M, N;
    scanf("%d", &T);
    rp(t,T) {
        scanf("%d%d%d%d", &R, &C, &M, &N);
        memset(add,0,sizeof add);
        rp(i,R) {
            scanf("%s", str);
            rp(j,C) add[str[j]-'A']++;
        }
        sort(add,add+26);
        most = add[25];
        sum = 0;
        rp(i,26) if(add[i]==most) sum+=add[i]*M;
                 else sum+=add[i]*N;
        printf("Case %d: %d\n", t+1, sum);
    }
    return 0;
}
