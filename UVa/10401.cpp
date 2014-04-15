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
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
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

#define N 100

ll pd[N][N];
char str[N];

int geti(char c) {
	if (c >= '1' && c <= '9') return c - '1';
	else return c - 'A' + 9;
}

int size;

ll solve(int ind, int last) {
	if (~pd[ind][last]) return pd[ind][last];
	if (ind == size) return pd[ind][last] = 1;
	
	if (str[ind] != '?') {
		int v = geti(str[ind]);
		if(last==(v-1) || last == v || last==(v+1)) return pd[ind][last] = 0;
		else return pd[ind][last] = solve(ind+1,v);
	}
	
	ll ret = 0;
	Fr(i,0,size) {
		if(last==(i-1) || last == i || last==(i+1)) continue;
		ret += solve(ind+1,i);
	}
	return pd[ind][last] = ret;
}

int main() {
	while (scanf("%s", str) == 1) {
		size = strlen(str);
		memset(pd,-1,sizeof pd);
		printf("%lld\n", solve(0,50));
	}
	return 0;
}