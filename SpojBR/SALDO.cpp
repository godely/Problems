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

int x[11000];

int main() {
	int n, cas = 1;
	int a, b;
	while (scanf("%d", &n) == 1 && n > 0) {
		rp(i,n) {
			scanf("%d%d", &a, &b);
			x[i] = a-b;
		}
		int acc = 0;
		int maxAcc = 0;
		int init = 0, ini, fim;
		rp(i,n) {
			acc += x[i];
			if (acc < 0) {
				acc = 0;
				init = i+1;
			}
			if (acc > maxAcc) {
				maxAcc = acc;
				ini = init;
				fim = i;
			}
			if (acc == maxAcc && i-init > fim-ini) {
				ini = init;
				fim = i;
			}
		}
		printf("Teste %d\n", cas++);
		if (maxAcc == 0) printf("nenhum\n");
		else printf("%d %d\n", ini+1, fim+1);
		puts("");
	}
	return 0;
}