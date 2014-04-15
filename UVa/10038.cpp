#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define LL long long

using namespace std;

int mark[3111], passo=0;
int main() {
    int N, a, b, c;
    bool ok;
    while (scanf("%d", &N) == 1) {
        scanf("%d", &a);
        ok = 1;
        passo++;
        fr(i,1,N) {
            scanf("%d", &b);
            if (ok) {
                c = abs(b-a);
                if (c < 1 || c >= N || mark[c]==passo) {
                    ok = 0;
                    continue;
                }
                mark[c] = passo;
                a = b;
            }
        }
        if (ok) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
