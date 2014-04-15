#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MP make_pair
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 1001000

int T, N, M;
int a[MAXN];
bool vis[MAXN];
int main() {
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int M = N*N;
		rp(i,M) scanf("%d", &a[i]);
		cl(vis,0);
		int cnt = 0;
		rp(i,M) {
			if (!vis[i]) {
				int s = a[i];
				vis[i] = 1;
				int cyc = 1;
				bool hasZero = (i == 0);
				while (s != i) {
					hasZero |= (s == 0);
					cyc++;
					vis[s] = 1;
					s = a[s];
				}
				cnt += (cyc-1);
				if (!hasZero && cyc > 1) {
					cnt+=2;
				}
			}
		}
		printf("Case %d: %d\n", cas++, cnt);
	}
}

// 7 2 4 5 0 6 8 3 1