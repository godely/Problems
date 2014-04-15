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

int pd[10010];

int main() {
	int n;
	int k = 1;
	int j = 0;
	for (int i = 1; i <= 10000; i++) {
		pd[i] = pd[i-1] + k;
		j++;
		if (j == k) j = 0, k++;
	}
	while (scanf("%d", &n) == 1 && n > 0) {
		printf("%d %d\n", n, pd[n]);
	}
	return 0;
}