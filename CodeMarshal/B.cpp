#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <cmath>
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
#define MOD 1000000007LL

ll C[40][40];
ll A[40];

void pre() {
	rp(i,30) C[i][0] = C[i][i] = 1;
	fr(i,2,30) fr(j,1,i) C[i][j] = C[i-1][j-1]+C[i-1][j];
}

int main() {
	pre();
	A[0] = 1;
	A[1] = 1;
	fr(n,1,23) {
		ll S = 0;
		rp(k,n+1) S += C[n][k] * A[k] * A[n-k];
		A[n+1] = S >> 1;
	}

	rp(i,24) printf("%d: %lld\n", i, A[i]);
	/*while (scanf("%d", &n) == 1) {
		rp(i,n) r[i] = i;
		COUNT = 0; cl(cnt,0);
		do {
			bool ok = 1;
			rp(i,n-1) {
				if (i&1) {
					if (r[i] < r[i+1]) {
						ok = 0;
						break;
					}
				} else {
					if (r[i] > r[i+1]) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) {
				COUNT++;
				cnt[r[0]]++;
			}
		} while (next_permutation(r,r+n));
		printf(" > %d\n", COUNT);
		rp(i, n) printf("%d: %d\n", i, cnt[i]);
	}*/
}