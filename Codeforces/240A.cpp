#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 1) {
		if (k == 0) puts("1");
		else puts("-1");
	} else {
		int m = (n>>1)-1;
		k -= m;
		if (k <= 0) printf("-1\n");
		else {
			int c = 1;
			rp(i,m) {
				if (c == k) c++;
				if (c == k*2) c++;
				printf("%d ", c++);
				if (c == k) c++;
				if (c == k*2) c++;
				printf("%d ", c++);
			}
			printf("%d %d", k, k*2);
			if (n&1) {
				if (c == k) c++;
				if (c == k*2) c++;
				printf(" %d", c);
			}
			puts("");
		}
	}
}