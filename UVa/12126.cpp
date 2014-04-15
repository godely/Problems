#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 0xfff

using namespace std;

int main() {
	int T, lim;
	long long n, a, b, minArea, minA, minB;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		n = ceil((double)n/5);
		lim = (int)ceil(sqrt(n));
		minArea = -1, minA, minB;
		for (int i = 1; i <= lim; i++) {
			a = ceil((double)n/i);
			a = 10*a + 2;
			b = 44*i + 4;
			if (minArea == -1 || a*b < minArea) {
				minArea = a*b;
				minA = a;
				minB = b;
			} else if (a*b == minArea && abs(a-b) < abs(minA-minB)) {
				minA = a;
				minB = b;
			}
		}
		printf("%lld X %lld = %lld\n", max(minA,minB), min(minA,minB), minA*minB);
	}
}