#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define LL long long

using namespace std;

bool C[1111111];
long long P[111111], p=0;

void sieve() {
    fr(i,2,1000001) {
        if (!C[i]) {
            P[p++]=i;
            for(LL j = (LL)i*i; j < 1000001; j+=i) C[j]=1;
        }
    }
}

int main() {
    sieve();
    int T;
    LL a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &a, &b);
        int c = 0;
        for (int i = 0; i < p && P[i]*P[i] <= b; i++) {
            for (long long j = P[i]*P[i]; j <= b; j*=P[i]) if (j >= a) c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
