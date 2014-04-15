//stor
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define P 10000

using namespace std;

int K[] = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main() {
    int T, cas=1;
    long long N;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        for (long long i = K[N]; i < K[N+1]; i++) {
            //printf("%lld %lld\n", (i*i)%K[N+1], i);
            if ((i*i)%K[N+1] == i) printf("%d ", i);
        }
        /*printf("Case #%d:", cas++);
        if (N==1) printf(" 0 1 5 6\n");
        else if (N==2) printf(" 25 76\n");
        else if (N==3) printf(" 376 625\n");
        else if (N==4) printf(" 9376\n");
        else printf(" Impossible\n");*/
    }
}
