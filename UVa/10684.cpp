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

int main() {
    int N, a;
    while (scanf("%d", &N) == 1 && N > 0) {
        int temp = 0, maxS = 0;
        rp(i,N) {
            scanf("%d", &a);
            if (temp+a < 0) temp=0;
            else temp+=a;
            maxS = max(temp,maxS);
        }
        if (maxS) printf("The maximum winning streak is %d.\n", maxS);
        else printf("Losing streak.\n");
    }
}
