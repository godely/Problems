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

int st[2*maxn+1000], fim = 0;
int main() {
	int n, a; scanf("%d", &n);
	int cnt = 0;
	while (n--) {
		scanf("%d", &a);
		if (a > 0) st[fim++] = a;
		else if (a < 0) printf("%d\n", st[--fim]);
		else {
			if (fim < n) {
				int tfim = fim;
				for (int i = 0; i < tfim; i++) st[fim++] = st[i];
			}
		}
	}
	return 0;
}