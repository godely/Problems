#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define LL long long

using namespace std;

int vet[111];
int main() {
    int N, a;
    while (scanf("%d", &N) == 1 && N > 0) {
        cl(vet,0);
        rp(i,N) scanf("%d", &a), vet[a]++;
        bool ok = 0;
        fr(i,1,101) rp(j,vet[i]) {
            if (ok) printf(" %d", i);
            else printf("%d", i), ok = 1;
        }
        printf("\n");
    }
    return 0;
}
