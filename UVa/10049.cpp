//by stor
#include <bits/stdc++.h>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define LIMIT 2000000000

using namespace std;

ll sum[1000000], size = 100, pos;

int main() {
	ll a;
	sum[0] = 0;
	sum[1] = 1;
	sum[2] = 3;
	int i = 3;
	while (sum[i-1] < LIMIT) {
		pos = lower_bound(sum+1, sum+i, i) - sum;
		sum[i] = sum[i-1] + pos;
		i++;
	}
	size = i;
	while (scanf("%lld", &a) == 1 && a > 0) {
		printf("%d\n", lower_bound(sum+1, sum+size, a) - sum);
	}
	return 0;
}