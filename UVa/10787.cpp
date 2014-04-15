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
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)

int amin, amax, bmin, bmax, mmin, mmax;
int T;
int main() {
	scanf("%d", &T);
	int cas = 1;
	while (T--) {
		scanf("%d%d%d%d%d%d", &amin, &amax, &bmin, &bmax, &mmin, &mmax);
		int res = 0;
		for (int b = bmin; b <= bmax; b++) {	
			for (int m = mmin; m <= mmax; m++) {
				//if ((a+b)%m == (a-b+10*m)%m) printf("%d %d %d\n", a, b, m), res++;
				if (m&1) res+=(b%m==0);
				else res+=(b%(m>>1)==0);
			}
		}
		res*=(amax-amin+1);
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}