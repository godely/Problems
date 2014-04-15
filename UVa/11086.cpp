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

#define MAXN 1148576

bool prime[MAXN+10];
int fat[MAXN+10];

void crivo() {
	cl(prime,1);
	fat[1] = 1;
	fat[2] = 2;
	for (int i = 4; i <= MAXN; i+=2) prime[i] = 0, fat[i] = 2;
	for (int i = 3; i <= MAXN; i+=2) {
		if (prime[i]) {
			fat[i] = i;
			for (int j = i*2; j <= MAXN; j+=i) {
				prime[j] = 0;
				fat[j] = i;
			}
		}
	}
}

int main() {
	crivo();
	int n;
	while (scanf("%d", &n) == 1) {
		int res = 0, k;
		rp(i,n) {
			scanf("%d", &k);
			int cnt = 0;
			while (k > 1 && cnt < 2) {
				k = k/fat[k];
				cnt++;
			}
			if (cnt == 2 && k == 1) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}