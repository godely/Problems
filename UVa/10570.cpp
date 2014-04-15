#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define ULL unsigned long long
#define inf 0xffffff

using namespace std;

int mark[511][511], passo=0;
int vet[511];

int main() {
    int N, k, c, m;
    while (scanf("%d", &N) == 1 && N > 0) {
        for (int i = 0; i < N; i++) scanf("%d", &vet[i]), vet[i]--;

        m = inf;
        for (int a = 0; a < 2; a++) {
        passo++;
        if (a==1) for (int i = 0; i < N/2; i++) swap(vet[i],vet[N-1-i]);
        //for (int i = 0; i < N; i++) printf("%d ", vet[i]);
        //printf("\n");
        for (int i = 0; i < N; i++) {
            c = 0;
            for (int j = 0; j < N; j++) {
                if (mark[i][j] != passo) {
                    k = (vet[j]+i)%N;
                    mark[i][j] = passo;
                    while (k != j) {
                        mark[i][k] = passo;
                        c++;
                        k = (vet[k]+i)%N;
                    }
                }
            }
            m = min(m,c);
        }
        }
        printf("%d\n", m);
    }
    return 0;
}
