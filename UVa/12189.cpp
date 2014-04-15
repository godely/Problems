#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second
#define MAXN 70000
#define mp make_pair

pair<int, char> K[MAXN];

int N, a, b, c;
char str[20];

int main() {
	int E, cnt, ans;
	while (scanf("%d", &N) == 1 && N > 0) {
		E = N/2;
		rp(i,N) {
			scanf("%d:%d:%d %s", &a, &b, &c, str);
			K[i] = mp(a*3600+b*60+c, str[0]);
			E -= (str[0] == 'E');
		}
		sort(K,K+N);
		cnt = ans = 0;
		rp(i,N) {
			if (K[i].S == 'E') cnt++;
			else if (K[i].S == 'X') cnt--;
			else {
				if (E) E--, cnt++;
				else cnt--;
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}