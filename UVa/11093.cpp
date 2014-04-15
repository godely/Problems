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

int N, a[100011], b[100011], k;
int x[100011], y[100011], id[100011];

int main() {
	int T, cas = 1;
	sf(T);
	while (T--) {
		sf(N);
		bool can = 0;
		rp(i,N) sf(a[i]);
		rp(i,N) sf(b[i]);
		rp(i,N) {
			x[i] = a[i]-b[i];
			if (x[i] >= 0) can = 1;
		}
		printf("Case %d: ", cas++);
		if (!can) printf("Not possible\n");
		else {
			int i = 0, j = N-1;
			while (j > i && ((x[j] >= 0 && x[j-1] >= 0) || (x[j] < 0 && x[j-1] < 0))) {
				x[j-1] += x[j];
				j--;
			}
			if (i == j) {
				if (x[0] >= 0) printf("Possible from station 1\n");
				else printf("Not possible\n");
			} else {
				N = j+1;
				if ((x[i] >= 0 && x[j] >= 0) || (x[i] < 0 && x[j] < 0)) x[i] += x[j], N = j;
				k = 0;
				for (i = 0; i < N; ) {
					y[k] = x[i];
					id[k] = i+1;
					while (i < N-1 && ((x[i] >= 0 && x[i+1] >= 0) || (x[i] < 0 && x[i+1] < 0))) y[k] += x[++i];
					k++; i++;
				}
				can = 0;
				for (i = 0; i < k; i++) {
					if (y[i] >= 0) {
						int s = y[i];
						can = 1;
						for (j = (i+1)%k; j != i; j = (j+1)%k) {
							s += y[j];
							if (s < 0) {
								can = 0;
								break;
							}
						}
						if (can) {
							printf("Possible from station %d\n", id[i]);
							break;
						}
					}
				}
				if (!can) printf("Not possible\n");
			}
		}
	}
	return 0;
}