#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100

int N;
char gb[30][30];

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) scanf("%s", gb[i]);
		int l, i_ini, j_ini;
		bool invalid = 0;
		rp(i,N) rp(j,N) {
			if (gb[i][j] == '#') {
				int k;
				for (k = j; gb[i][k] == '#'; k++);
				l = k-j;
				i_ini = i;
				j_ini = j;
				goto aff;
			}
		}
		aff:;
		fr(i,i_ini,i_ini+l) fr(j,j_ini,j_ini+l) {
			if (gb[i][j] != '#') {
				invalid = 1;
				goto fim;
			}
			gb[i][j] = '.';
		}
		fim:;
		if (!invalid) rp(i,N) rp(j,N) if (gb[i][j] == '#') invalid = 1;
		if (invalid) printf("Case #%d: NO\n", cas++);
		else printf("Case #%d: YES\n", cas++);
	}
}