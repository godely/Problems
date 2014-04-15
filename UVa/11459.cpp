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

int use[111], to[111], passo=0;
int POS[1111111];

int main() {
    int T, N, b, c, x, y;
    scanf("%d", &T);
    while (T--) {
        passo++;
        scanf("%d%d%d", &N, &b, &c);
        rp(i,N) POS[i] = 1;
        rp(i,b) {
            scanf("%d%d", &x, &y);
            use[x] = passo;
            to[x] = y;
        }
        bool gaming = true;
        rp(i,c) {
            scanf("%d", &x);
            if (gaming) {
                if (use[POS[i%N]+x] == passo) POS[i%N] = to[POS[i%N]+x];
                else POS[i%N]+=x;
                if (POS[i%N] >= 100) {
                    POS[i%N] = 100;
                    gaming = false;
                }
            }
        }
        fr(i,1,N+1) printf("Position of player %d is %d.\n", i, POS[i-1]);
    }
}
