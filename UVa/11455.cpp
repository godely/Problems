#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

int l[10];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		rp(i,4) scanf("%d", &l[i]);
		sort(l,l+4);
		if (l[0] == l[3]) printf("square\n");
		else if (l[0] == l[1] && l[2] == l[3]) printf("rectangle\n");
		else if (l[0] + l[1] + l[2] >= l[3]) printf("quadrangle\n");
		else printf("banana\n");
	}
	return 0;
}