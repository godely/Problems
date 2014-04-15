#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define fr(a,b,c) for(int a = b; a<c; a++)
#define rp(a,b) fr(a,0,b)

int P[10][111111], size[10];

int p, s, d;
char str[20];

int main() {
	rp(a,10) P[0][size[0]++] = a*10 + a;
	rp(a,10) rp(b,10) P[1][size[1]++] = a*100 + b*10 + a, P[2][size[2]++] = a*1000 + b*100 + b*10 + a;
	rp(a,10) rp(b,10) rp(c,10) P[3][size[3]++] = a*10000 + b*1000 + c*100 + b*10 + a, P[4][size[4]++] = a*100000 + b*10000 + c*1000 + c*100 + b*10 + a;
	rp(a,10) rp(b,10) rp(c,10) rp(d,10) P[5][size[5]++] = a*1000000 + b*100000 + c*10000 + d*1000 + c*100 + b*10 + a, P[6][size[6]++] = a*10000000 + b*1000000 + c*100000 + d*10000 + d*1000 + c*100 + b*10 + a;
	rp(a,10) rp(b,10) rp(c,10) rp(d,10) rp(e,10) P[7][size[7]++] = a*100000000 + b*10000000 + c*1000000 + d*100000 + e*10000 + d*1000 + c*100 + b*10 + a;
	
	while (scanf("%s", str) == 1) {
		s = strlen(str)-2;
		p = atoi(str);
		if (!p && s==-1) break;
		d = lower_bound(P[s], P[s]+size[s], p) - P[s];
		printf("%d\n", P[s][d] - p);
	}
	return 0;
}