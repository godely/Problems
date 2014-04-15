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

int main() {
    int N, B, H, W, a, peso;
    while (scanf("%d%d%d%d", &N, &B, &H, &W) == 4) {
        int maximo = inf;
        rp(i,H) {
            scanf("%d", &peso);
            rp(j,W) {
                scanf("%d", &a);
                if (a >= N && peso*N < maximo) {
                    maximo = peso*N;
                }
            }
        }
        if (maximo > B) printf("stay home\n");
        else printf("%d\n", maximo);
    }
    return 0;
}
