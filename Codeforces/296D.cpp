#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for (int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define LSOne(x) (x&(-x))
typedef long long ll;
#define maxn 511

int n;
int x[maxn], mark[maxn];
ll cap[maxn][maxn];
void fw() {
	ll sum;
	vector<ll> vec;
	Rp(k,n) {
		sum = 0;
		Rp(i,n) Rp(j,n) {
			cap[i][j] = min(cap[i][j], cap[i][x[k]] + cap[x[k]][j]);
			//printf("x[k]:%d i:%d j:%d, mark[i]:%d, mark[j]:%d, %lld\n", x[k], i, j, mark[i], mark[j], cap[i][j]);
			if (mark[i] <= k && mark[j] <= k) sum += cap[i][j];
		}
		vec.push_back(sum);
	}
	reverse(vec.begin(), vec.end());
	printf("%I64d", vec[0]);
	Fr(i,1,n) printf(" %I64d", vec[i]);
	printf("\n");
}

int main() {
	scanf("%d", &n);
	Rp(i,n) Rp(j,n) scanf("%lld", &cap[i][j]);
	Rp(i,n) scanf("%d", &x[n-1-i]), x[n-1-i]--, mark[x[n-1-i]] = n-1-i;
	fw();
	return 0;
}