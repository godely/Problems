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

char str[1000];

int main() {
	int T, N;
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
	    scanf("%d%s", &N, str);
		int b = 0, w = 0, t = 0, a = 0;
		for (int i = 0; str[i]; i++) {
		    if (str[i] == 'B') {
		        b++;
		    } else if(str[i] == 'W') {
		        w++;
		    } else if (str[i] == 'T') {
		        t++;
		    } else if (str[i] == 'A') {
		        a++;
		    }
		}
		printf("Case %d: ", cas++);
		if (b > 0 && w == 0 && t == 0) printf("BANGLAWASH");
		else if (w > 0 && b == 0 && t == 0) printf("WHITEWASH");
		else if (w == 0 && b == 0 && t == 0 && a > 0) printf("ABANDONED");
		else if (w == b) printf("DRAW %d %d", w, t);
		else if (b > w) printf("BANGLADESH %d - %d", max(b,w), min(b,w));
		else printf("WWW %d - %d", max(b,w), min(b,w));
		puts("");
	}
	return 0;
}