#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int n, k;
char str[1000];
int rem[30];
int main() {
	int T, count, res, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &k, str);
		memset(rem, 0, sizeof rem); res = 0;
		rp(i,n) {
			if (rem[str[i]-'A'] > 0) res++;
			rem[str[i]-'A']++;
			if (i >= k) {
				rem[str[i-k]-'A']--;
			}
		}
		printf("Case %d: %d\n", cas++, res);
	}
}