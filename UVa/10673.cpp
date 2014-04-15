#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	int x, k;
	while (T--) {
		scanf("%d%d", &x, &k);
		int q = x%k;
		int p = k - q;
		printf("%d %d\n", p, q);
	}
}
