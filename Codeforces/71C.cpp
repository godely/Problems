#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define ifr(a,b,c) for(int a=b; a>=c; a--)
#define rp(a,b) fr(a,0,b)

using namespace std;

int vet[111111];
int main() {
    int N;
    scanf("%d", &N);
    bool ok=0, temp=1;
    rp(i,N) {
        scanf("%d", &vet[i]);
        if (!vet[i]) temp=0;
    }
    if (temp) ok=1;

    int k, t;
    for (int i = 3; i <= N/2 && !ok; i++) {
        k = i, t=N/i;
        if (N%i==0 && k>2) {
            //printf("%d %d\n", k, t);
            for (int j = 0; j < t; j++) {
                if (vet[j] == 0) continue;
                for (int k = (j+t)%N; k != j; k = (k+t)%N) {
                    if (vet[k]==0) {
                        goto aff;
                    }
                }
                ok=1;
                break;
                aff:;
            }
        }
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
}
