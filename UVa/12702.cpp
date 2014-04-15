#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define MAXN 2100100

int n, m, r, c;
bool x[111][111], y[12][12], z[111][111];

int main() {
    int T, cas = 1, af;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        rp(i,n) rp(j,m) scanf("%d", &af), x[i][j] = af;
        scanf("%d%d", &r, &c);
        rp(i,r) rp(j,c) scanf("%d", &af), y[i][j] = af;
        int di = r>>1, dj = c>>1;
        cl(z,0);
        rp(i,n-di) rp(j,m-dj) {
            if (x[i+di][j+dj]) {
                rp(a,r) rp(b,c) z[i+a][j+b] |= x[i+a][j+b]|y[a][b];
            }
        }
        printf("Case %d:\n", cas++);
        rp(i,n) {
            printf("%d", z[i][0]);
            fr(j,1,m) printf(" %d", z[i][j]);
            puts("");
        }
    }
    return 0;
}