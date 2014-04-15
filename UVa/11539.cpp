//by stor
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int mod = (1<<27);
const long long base = 37LL;
int N, P, hash[1<<27], hash2[1<<27], passo=0, size, calc[11111], pd[11111];
char gb[11111];

int solve(int ind) {
    if (ind >= size) return 0;
    if (calc[ind]==passo) return pd[ind];
    calc[ind] = passo;

    int res = solve(ind+1)-P, sum = 0;
    for (int i = ind, j = 0; i < ind+100 && i < size; i++, j++) {
        sum=(sum*base+(gb[i]-'a'+1))%mod;
        //printf("ind:%d, hash:%d, i:%d\n", ind, sum, j);
        if (hash[sum] == passo) {
            res = max(res, solve(i+1)+hash2[sum]);
//            printf("> %d %d %d %d\n", i, sum, hash2[sum], res);
        }
    }
//    printf("%d %d\n", ind, res);
    return pd[ind] = res;
}

int main() {
    int T, S, cas = 1;
    scanf("%d", &T);
    while (T--) {
        passo++;
        scanf("%d%d", &N, &P);
        for (int i = 0; i < N; i++) {
            scanf("%s%d", gb, &S);
            int size = strlen(gb);
            long long sum=0;
            for (int j = 0; j < size; j++) {
                sum=(sum*base+(gb[j]-'a'+1))%mod;
            }
            hash[sum]=passo;
            hash2[sum]=S;
//            printf("> %d\n", sum);
        }
        scanf("%s", gb);
        size = strlen(gb);
        printf("Case %d: %d\n", cas++, solve(0));
    }
}
