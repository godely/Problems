#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair
typedef long long ll;

ll v[1111];
int main() {
	ll n, k;
	cin >> n >> k;
	Rp(i,n) cin >> v[i];
	sort(v,v+n);
	ll i = 0, j, size, ans1 = 0, ans2 = 0, cnt = 0;
	while (i < n) {
		j = upper_bound(v+i,v+n,v[i]) - v;
		size = (j-i);
		//printf("%d %d, %d %d %d\n", i, j, v[i], cnt, size);
		if ((cnt + size)*v[i] <= k) cnt += size;
		else {
			if (!cnt || cnt*v[i-1] > k) break;
			ans1 += cnt, ans2++;
			cnt = size;
		}
		i = j;
	}
	if (cnt > 0 && cnt*v[i-1] <= k) ans1 += cnt, ans2++;
	cout << ans1 << " " << ans2 << endl;
}