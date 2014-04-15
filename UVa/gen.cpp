#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
#define inf 0x3f3f3f3f

int main() {
	srand(time(NULL));
	rp(i,1) {
		int k = 7;
		printf("%d\n", k);
		rp(i,k) {
			rp(j,k) printf("%d ", rand()%20+1);
			printf("\n");
		}
	}
	return 0;
}