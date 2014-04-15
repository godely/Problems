#include <bits/stdc++.h>

using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

long long v[1010], sum;

int main() {
	int T, N, c;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		sum = 0;
		rp(i,N) scanf("%lld", &v[i]);
		v[N] = 100000000000000000LL;
		c = 0;
		rp(i,N) {
			if (sum + v[i] < v[i+1]) sum += v[i], c++;
		}
		printf("%d\n", c);
	}
	return 0;
}