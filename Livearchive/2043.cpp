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

int xmin[10000], xmax[10000], ymin[10000], ymax[10000];

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n > 0) {
		rp(i,n) {
			scanf("%d%d%d%d", &xmin[i], &xmax[i], &ymin[i], &ymax[i]);
		}
		int cnt = 0;
		rp(i,n) {
			rp(j,n) if (i != j) {
				if (xmin[i] >= xmin[j] && xmax[i] <= xmax[j] && ymin[i] >= ymin[j] && ymax[i] <= ymax[j]) {
					cnt++;
					break;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}