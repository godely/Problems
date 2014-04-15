#include <bits/stdc++.h>
using namespace std;

int n;
double p, probA, probB, nprobA, nprobB;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%lf", &n, &p);
		probA = p;
		probB = 1-p;
		for (int i = 1; i < n; i++) {
			nprobA = p*probB + (1-p)*probA;
			nprobB = p*probA + (1-p)*probB;
			probA = nprobA, probB = nprobB;
		}
		printf("%.6lf\n", probA);
	}
	return 0;
}