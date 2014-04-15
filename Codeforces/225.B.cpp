#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

long long F[500];
int res[500];

int main() {
    int s, k;
    scanf("%d%d", &s, &k);

    F[0]=0;
    F[1]=1;

    int i;
    for (i = 2;; i++) {
        for (int j = i-1; j >= 0 && j >= i-k; j--) F[i] += F[j];
        if (F[i] > s) break;

    }

    int count = 0;
    for(i=i-1; i >= 0; i--) {
        if (F[i] <= s) s-=F[i], res[count++] = F[i];
    }

    printf("%d\n", count);
    printf("%d", res[count-1]);
    for(i=count-2; i >= 0; i--) printf(" %d", res[i]);
    printf("\n");
}
