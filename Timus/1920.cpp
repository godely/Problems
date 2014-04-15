#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair
typedef long long ll;
#define maxn 1000100

int main() {
	int n, l;
	scanf("%d%d", &n, &l);
	if (l&1 || l > n*n) printf("Unsuitable device\n");
	else {
		printf("Overwhelming power of magic\n");
		int k = l>>1;
		if (k <= n) {
			Rp(i,k) printf("%d 1\n", i+1);
			Rp(i,k) printf("%d 2\n", k-i);
		} else {
			Rp(i,n) printf("%d 1\n", i+1);
			k-=n;
			int x = n;
			while (k > 0) {
				int p = min(k,n-2);
				k -= p;
				Rp(i,p+1) printf("%d %d\n", x, i+2);
				Rp(i,p+1) {
					printf("%d %d\n", x-1, p+2-i);
					if (n&1 && x == 3 && k) {
						printf("%d %d\n%d %d\n%d %d\n", x-2, p+2-i, x-2, p+1-i, x-1, p+1-i);
						++i; --k;
					}
				}
				x -= 2;
			}
			Rp(i,x) printf("%d 2\n", x-i);
		}
	}
	return 0;
}