#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

int get(char c) {
	if (c == 'A') return 0;
	else if (c == 'C') return 1;
	else if (c == 'G') return 2;
	return 3;
}

char nm[50];
int ar[21000];
map<ll,int> mp;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n > 0) {
		mp.clear();
		rp(i,n) {
			scanf("%s", nm);
			ll hash = 0;
			rp(j,m) hash = hash*4 + get(nm[j]);
			mp[hash]++;
		}
		cl(ar,0);
		for (map<ll,int>::iterator it = mp.begin(); it != mp.end(); it++) {
			ar[(*it).S-1]++;
		}
		rp(i,n) printf("%d\n", ar[i]);
	}
	return 0;
}
/*
9 6
AAAAAA

ACACAC
ACACAC
ACACAC
ACACAC


GTTTTG
GTTTTG

TCCCCC
TCCCCC
0 0
*/