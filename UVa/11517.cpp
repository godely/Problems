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

int vet[111];
int knap[21111];
int main() {
    int T, N, q;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        memset(knap,0x3f,sizeof knap);
        scanf("%d", &q);
        rp(i,q) {
            scanf("%d", &vet[i]);
        }
        int res = inf, kate=inf;
        knap[0] = 0;
        for (int i = 0; i < q; i++) {
            for (int j = N+vet[i]; j >= vet[i]; j--) {
                knap[j] = min(knap[j], knap[j-vet[i]]+1);
                //if (i == 3) printf("%d %d %d\n", vet[i], knap[j], j);
                if (j >= N && knap[j] < inf && j-N <= kate) {
                    //printf("%d %d %d\n", i, j, knap[j]);
                    if (j-N < kate) res = knap[j];
                    else res = min(res, knap[j]);
                    kate = j-N;
                }
            }
        }
        printf("%d %d\n", N+kate, res);
    }
    return 0;
}
