#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair

int a[1111], q, t;
int main() {
	int n;
	scanf("%d", &n);
	scanf("%d%d", &a[0], &a[1]);
	q = 0;
	Fr(i,2,n) {
		scanf("%d", &a[i]);
		if (a[i-2]+a[i-1]+a[i] > q) {
			q = a[i-2]+a[i-1]+a[i];
			t = i-1;
		}
	}
	printf("%d %d\n", q, t+1);
}