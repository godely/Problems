#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int main() {
    int N, top, a, b;
    scanf("%d%d", &N, &top);
    bool ok = 1;
    int k = 7-top;
    rp(i,N) {
        scanf("%d%d", &a, &b);
        if(ok)if (k==a || k==b || k==7-a || k==7-b) ok=0;
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
}
