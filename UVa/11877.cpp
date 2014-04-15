#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, res;
	while (scanf("%d", &n) == 1 && n > 0) {
		res = 0;
		while (n > 2) {
			res += n/3;
			n = n/3 + n%3;
		}
		printf("%d\n", res + (n==2));
	}
	return 0;
}