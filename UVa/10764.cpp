#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int seq[20];
int main() {
	bool sign;
	int pos;
	long long n, b, a;
	while (scanf("%lld%lld%lld", &n, &b, &a) == 3 && b > 0) {
		if (n == 0) {
			printf("0\n");
			continue;
		}
		sign = 0;
		if (n<0) sign = 1, n=-n;
		pos = 0;
		memset(seq, 0, sizeof seq);
		while (n) {
			seq[pos++] = sign? -(n%b) : n%b;
			n/=b;
		}
		for (int i = 0; i < pos; i++) {
			if (seq[i] < -a) seq[i] += b, seq[i+1]--;
			else if (seq[i] > a) seq[i] -= b, seq[i+1]++;
		}
		for (int i = (seq[pos])?pos:pos-1; i >= 0; i--) {
			if (seq[i]<0) printf("'%d", -seq[i]);
			else printf("%d", seq[i]);
		}
		printf("\n");
	}
}