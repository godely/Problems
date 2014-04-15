#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 213244613217LL

using namespace std;

int N;
long long grid1[1111][1111], grid2[1111][1111], vet[1111], ans1[1111], ans2[1111], ans3[1111];

bool isEqual() {
    rp(i,N) vet[i]=rand()%177;
    memset(ans1, 0, sizeof ans1);
    memset(ans3, 0, sizeof ans3);
    rp(i,N) rp(k,N) ans1[i] = (ans1[i]+grid1[i][k]*vet[k])%mod;
    rp(i,N) rp(k,N) ans3[i] = (ans3[i]+grid1[i][k]*ans1[k])%mod;
    memset(ans2, 0, sizeof ans2);
    rp(i,N) rp(k,N) ans2[i] = (ans2[i]+grid2[i][k]*vet[k])%mod;
    rp(i,N) if (ans2[i] != ans3[i]) return 0;
    return 1;
}

int main() {
    while (scanf("%d", &N) == 1 && N > 0) {
        rp(i,N) rp(j,N) scanf("%lld", &grid1[i][j]);
        rp(i,N) rp(j,N) scanf("%lld", &grid2[i][j]);
        if (isEqual()) printf("YES\n");
        else printf("NO\n");
    }
}
