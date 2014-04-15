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
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

const double cst = sqrt(3.0)/2.0;
pair<double,double> t[] = {MP(1,0), MP(0.5,cst), MP(-0.5, cst), MP(-1,0), MP(-0.5, -cst), MP(0.5, -cst)};
pair<double,double> p[10000010];

int main() {
	p[0] = MP(0,0);
	for (int i = 1, d = 1; ; d++) {
		for (int j = 0; j < 6; j++) {
			if (j == 1) d--;
			rp(k,d) {
				p[i] = MP(p[i-1].F+t[j].F, p[i-1].S+t[j].S);
				i++;
				if (i > 10000000) goto lolol;
			}
			if (j == 1) d++;
		}
	}
	lolol:;
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		printf("%.3lf %.3lf\n", (double)abs(a-b), sqrt((p[a].F-p[b].F)*(p[a].F-p[b].F) + (p[a].S-p[b].S)*(p[a].S-p[b].S)));
	}
}