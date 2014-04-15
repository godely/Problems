#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define LL long long

using namespace std;

bool C[1111111];
int P[1111111], p=0;
void sieve() {
    C[0] = C[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (!C[i]) {
            P[p++]=i;
            for (long long j = (long long)i*i; j <= 1000000; j+=i) {
                C[j] = 1;
            }
        }
    }
}

LL expmod(LL a, LL s, LL p) {
    LL ret=1;
    for (; s > 0; s >>= 1, a=(a*a)%p) if (s&1) ret=(ret*a)%p;
    return ret;
}

bool Miller(LL p, LL s, int a) {
    if (p==a) return 1;
    LL mod=expmod(a,s,p);
    for(;s-p+1 && mod-1 && mod-p+1; s*=2) mod = (mod*mod)%p;
    return mod==p-1 || s%2;
}

bool isprime(LL n) {
    if (n<2) return 0;
    if (n%2==0) return n==2;
    LL s=n-1;
    while (s%2==0) s/=2;
    return Miller(n,s,2) && Miller(n,s,7) && Miller(n,s,61);
}

int main() {
    int N;
    sieve();
    while (scanf("%d", &N) == 1 && N > 0) {
        bool ok = 0;
        for (int i = 1; i < p && P[i] < N; i++) {
            if (!C[N-P[i]]) {
                printf("%d = %d + %d\n", N, P[i], N-P[i]);
                ok = 1;
                break;
            }
        }
        if (!ok) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
