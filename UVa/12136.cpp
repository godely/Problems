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
#define cl(a,b) memset(a,b,sizeof(a))
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

#define dbg if(0)

int mark[100000], passo = 0;
int h1, m1, h2, m2;

int main() {
	cl(mark,0);
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
		h1 = h1*60 + m1; h2 = h2*60 + m2;
		passo++;
		fr(i,h1,h2+1) mark[i] = passo;
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
		h1 = h1*60 + m1; h2 = h2*60 + m2;
		bool conflict = 0;
		fr(i,h1,h2+1) if (mark[i] == passo) {
			conflict = 1;
		}
		if (conflict) printf("Case %d: Mrs Meeting\n", cas++);
		else printf("Case %d: Hits Meeting\n", cas++);
	}
	return 0;
}