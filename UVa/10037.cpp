#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pii pair<int,int>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int vet[1111];
int res[4222], s;

int main() {
    int T, N;
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        rp(i,N) scanf("%d", &vet[i]);

        sort(vet,vet+N);

        if (N == 0) printf("%d\n", 0);
        else if (N == 1) {
            printf("%d\n%d\n", vet[0], vet[0]);
        } else if (N == 2) {
            printf("%d\n%d %d\n", vet[1], vet[0], vet[1]);
        } else {
            s=0;
            int count = vet[1];
            int i;
            for (i = N-1; i > 1; i-=2) {
                if (i == 2) {
                    res[s++]=vet[0];
                    res[s++]=vet[i];
                    res[s++]=vet[0];
                    count += vet[i]+vet[0];
                    break;
                }
                if (vet[i-1]+vet[0] < 2*vet[1]) {
                    res[s++]=vet[0];
                    res[s++]=vet[i];
                    res[s++]=vet[0];
                    res[s++]=vet[0];
                    res[s++]=vet[i-1];
                    res[s++]=vet[0];
                    count += vet[i]+vet[i-1]+2*vet[0];
                } else {
                    res[s++]=vet[0];
                    res[s++]=vet[1];
                    res[s++]=vet[0];
                    res[s++]=vet[i-1];
                    res[s++]=vet[i];
                    res[s++]=vet[1];
                    count += 2*vet[1]+vet[0]+vet[i];
                }
            }
            res[s++]=vet[0];
            res[s++]=vet[1];
            printf("%d\n", count);
            int k = 0;
            for(int i = 0; k < s; i++) {
                if (i&1) printf("%d\n", res[k++]);
                else printf("%d %d\n", res[k++], res[k++]);
            }
        }
        if (T>0) printf("\n");
    }
    return 0;
}
