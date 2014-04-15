#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <queue>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int P[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
unsigned long long knap[61111];

int main() {
    knap[0] = 1;
    for (int i = 0; i < 11; i++) {
        for (int j = P[i]; j <= 60000; j++) {
            knap[j] += knap[j-P[i]];
        }
    }
    double N;
    int K;
    while (scanf("%lf", &N) == 1 && N > 0) {
        K = (int)(20.0*N);
        int esp1 = (N < 1.0) ? 2 : 2-(int)log10(N);
        int esp2 = 16-(int)log10(knap[K]);
        rp(i,esp1) printf(" ");
        printf("%.2lf", N);
        rp(i,esp2) printf(" ");
        printf("%lld\n", knap[K]);
    }
    return 0;
}
