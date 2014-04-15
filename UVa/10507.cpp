#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define LSOne(x) (x&(-x))
#define MAXN 1000010
#define p(x) str[x]-'A'
#define inf 0x3f3f3f3f

using namespace std;

int adj[30][30], size[30];
char str[20];
bool use[30];
int wake[30];

bool cmp(int a, int b) {
	return wake[a] < wake[b];
}

int main() {
	int N, M;
	while (scanf("%d", &N) == 1) {
		scanf("%d", &M);
		scanf("%s", str);
		memset(use, 0, sizeof use);
		memset(wake, 0x3f, sizeof wake);
		memset(size, 0, sizeof size);
		use[p(0)] = use[p(1)] = use[p(2)] = 1;
		wake[p(0)] = wake[p(1)] = wake[p(2)] = 0;
		rp(i,M) {
			scanf("%s", str);
			use[p(0)] = use[p(1)] = 1;
			adj[p(0)][size[p(0)]++] = p(1);
			adj[p(1)][size[p(1)]++] = p(0);
		}
		bool ok = 1;
		int k, t = 3;
		for (k = 0; k < 30 && t < N && ok; k++) {
			for (int i = 0; i < 26; i++) {
				if (use[i]) {
					if (wake[i] == inf && size[i] < 3) {
						ok = 0;
						break;
					}
					if (wake[i] == inf) {
						sort(adj[i], adj[i]+size[i], cmp);
						if (wake[adj[i][2]] > k) continue;
						//printf("(%d) %c: %c %c %c\n", k, i+'A', adj[i][0]+'A', adj[i][1]+'A', adj[i][2]+'A');
						t++;
						wake[i] = 1+max(wake[adj[i][0]], max(wake[adj[i][1]], wake[adj[i][2]]));
					}
				}
			}
		}
		if (!ok || k==30) printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n", k);
	}
	return 0;
}