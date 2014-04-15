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
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define MAXN 10111
int N, M;
int st, dur;
int cnt;
pii s[MAXN];

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		rp(i,N) {
			scanf("%*d%*d%d%d", &st, &dur);
			s[i] = MP(st,st+dur-1);
		}
		rp(i,M) {
			scanf("%d%d", &st, &dur);
			dur = dur+st-1;
			cnt = 0;
			rp(j,N) if ((s[j].F >= st && s[j].F <= dur) || (s[j].S >= st && s[j].S <= dur) || (s[j].F <= st && s[j].S >= dur)) cnt++;
			printf("%d\n", cnt);
		}
	}
	return 0;
}