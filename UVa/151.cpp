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

bool P[111];
int main() {
    int N;
    while (scanf("%d", &N) == 1 && N > 0) {
        for (int i = 1; i <= 200; i++) {
            memset(P,1,sizeof P);
            int k = N, st = 0;
            while (k > 1) {
                P[st] = 0;
                int j = (st+1)%N;
                for (int c = 0;; j=(j+1)%N) {
                    if (P[j]) c++;
                    if (c >= i) break;
                }
                st = j;
                k--;
            }
            if (st == 12) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
