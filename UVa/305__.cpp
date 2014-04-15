//too slow
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define prox(i) (i+1)%N
#define ant(i) (i+N-1)%N

using namespace std;

int passo=0;
int prev[50], next[50];
int main() {
    int K, N, m, j, c;
    while (scanf("%d", &K) == 1 && K > 0) {
        N = 2*K;
        for (int i = 1; i <= 30000000; i++) {
            for (int i = 0; i < N; i++) next[i] = prox(i), prev[i] = ant(i);
            j = 0, m = 0;
            while (1) {
                for (c = 1; c < i; c++, j=next[j]);
                //printf("%d\n", j);
                next[prev[j]] = next[j];
                prev[next[j]] = prev[j];
                if (j < K) break;
                j = next[j];
                m++;
                if (m >= K) {
                    printf("%d\n", i);
                    goto lol;
                }
            }
            //printf("\n");
        }
        lol:;
    }
    return 0;
}
