#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

bool C[10001];
int P[100000], p=0;

int expo(int a, int b, int mod) {
    if (b==0) return 1;
    if (b==1) return a;
    int aux = expo(a,b/2,mod);
    aux = (aux*aux)%mod;
    if (b&1) aux=(aux*a)%mod;
    return aux;
}

void sieve() {
    for (int i = 2; i <= 10000; i++) {
        if (!C[i]) {
            P[p++] = i;
            for (int j = i*i; j <= 10000; j+=i) C[j] = 1;
        }
    }
}

int phi(int n) {
    int m = n;
    for (int i = 0; i < p && P[i] <= n; i++) {
        if (n%P[i]==0) {
            m-=m/P[i];
        }
    }
    return m;
}

int vet[12], N;
int solve(int i, int mod) {
    if (vet[i] == 1 || i >= N) return 1;
    //if (mod == 1) return 0;

    int y = phi(mod);
    int x = expo(vet[i], solve(i+1, y)%y, mod);
    //printf("%d %d\n", x, y);
    return x;
}

int main() {
    sieve();
    int Mod, cas = 1;
    while (scanf("%d", &Mod) == 1 && Mod) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &vet[i]);
        printf("Case #%d: %d\n", cas++, solve(0, Mod));
    }
    return 0;
}
