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
#define PB push_back
#define MP make_pair
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define prox(i) (((i)+1)%n)
#define ant(i) (((i)-1+n)%n)
#define dbg if(0)
#define F first
#define S second
#define isLet(i) (gb[i] >= 'a' && gb[i] <= 'z')
typedef pair<int,int> pii;

char gb[1111], str[1111];
int k, n, sz;
int er[1111][1111];
int ind[1111];

pii go() {
	memset(er,0,sizeof er);
	fr(i,1,sz) fr(j,0,sz-i) er[j][j+i] = (str[j] != str[j+i]) + er[j+1][j+i-1];
	
	int ans1 = 1, ans2 = 1;
	fr(i,0,n) fr(j,i,n) {
		if(isLet(i) && isLet(j) && er[ind[i]][ind[j]] <= k) {
			if (j-i+1 > ans1) ans1 = j-i+1, ans2 = i+1;
		}
	}
	return MP(ans1,ans2);
}

int main() {
	int cas = 1;
	while (scanf("%d", &k) == 1) {
		gets(gb); gets(gb);
		n = strlen(gb);
		sz = 0;
		for (int i = 0; gb[i]; i++) {
			gb[i]|=32;
			if (isLet(i)) {
				ind[i] = sz;
				str[sz++] = gb[i];
			}
		}
		str[sz] = 0;
		pii aux = go();
		printf("Case %d: %d %d\n", cas++, aux.F, aux.S);
	}
	return 0;
}