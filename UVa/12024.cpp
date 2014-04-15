#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int num[100], fat[100];
int main() {
	num[0] = 0; fat[0] = 1;
	num[1] = 0; fat[1] = 1;
	num[2] = 1; fat[2] = 2;
	fr(i,3,13) {
		num[i] = (i-1)*(num[i-1]+num[i-2]);
		fat[i] = i*fat[i-1];
	}
	int t, n;
	scanf("%d", &t);
	while (t--) scanf("%d", &n), printf("%d/%d\n", num[n], fat[n]);
}