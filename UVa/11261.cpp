#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#include <cassert>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define maxn 101000

int n, m, a, b, res;
int getId1(int i, int j) { return i-j+40000; }
int getId2(int i, int j) { return i+j; }
int getSize1(int i, int j) { return n-max(i-j,j-i); }
int getSize2(int i, int j) {
	if (n-i > j+1) i += j, j = 0;
	else j-=(n-i-1), i = n-1;
	return min(i+1,n-j);
}

bitset<maxn> mark1;
bitset<maxn> mark2;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		res = 0;
		mark1.reset();
		mark2.reset();
		rp(i,m) {
			scanf("%d%d", &a, &b); a--, b--;
			if (!mark1[getId1(a,b)]) {
				mark1[getId1(a,b)] = 1;
				res -= getSize1(a,b);
				res += mark2[getId2(a,b)];
			}
			if (!mark2[getId2(a,b)]) {
				mark2[getId2(a,b)] = 1;
				res -= getSize2(a,b);
				res += mark1[getId1(a,b)];
			}
		}
		printf("%d\n", res);
	}
}
