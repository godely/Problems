#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;

int T;
ull n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%llu", &n);
        printf("%llu\n", (n>>1)*((n-1)>>1));
    }
    return 0;
}