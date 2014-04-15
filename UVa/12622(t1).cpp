#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

int go(int n, int b) {
	int ret = 0;
	while (n) {
		if (n%b == 4) ret++;
		n/=b;
	}
	return ret;
}

int main() {
	int T, P; scanf("%d", &T);
	for (P = 10000000; P <= 10010000; P++) {
		//scanf("%d", &P);
		int fou = 0, temp, res;
		fr(i,5,P+2) {
			temp = go(P,i);
			if (temp > fou) {
				fou = temp;
				res = i;
			}
		}
		if (!fou) printf("%d is infuriable.\n", P);
		else printf("%d %d %d\n", P, fou, res);
	}
	return 0;
}