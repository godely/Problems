#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof(a))
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

int N, X, Y, cnt[105], Num;
int main() {
	while (scanf("%d", &N) == 1) {
		cl(cnt,0);
		rp(i,N) {
			scanf("%d%d", &X, &Y);
			fr(i,X,Y+1) cnt[i]++;
		}
		fr(i,1,101) cnt[i] += cnt[i-1];
		scanf("%d", &Num);
		if (cnt[Num] == cnt[Num-1]) printf("%d not found\n", Num);
		else printf("%d found from %d to %d\n", Num, cnt[Num-1], cnt[Num]-1);
	}
}