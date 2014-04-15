#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long vet[30000];

int main() {
	int k;
	vet[0] = 0;
	vet[1] = 1;
	for (k = 2; vet[k-1] <= 1000000100; k++)
		vet[k] = vet[k-1] + 4*(k-2) + 5;
	long long A, B, dif;
	int xa, ya, xb, yb;
	bool hasFoundA, hasFoundB;
	while (scanf("%lld%lld", &A, &B) && ~A) {
		hasFoundA = false, hasFoundB = false;
		for (int i = 0; i < k && (!hasFoundA || !hasFoundB); i++) {
			if (!hasFoundA && vet[i] <= A && vet[i+1] > A) {
				hasFoundA = true;
				dif = A-vet[i];
				if (dif <= i) {
					xa = dif;
					ya = i - dif;
				} else if (dif <= 2*i) {
					xa = 2*i - dif;
					ya = -(dif - i);
				} else if (dif <= 3*i) {
					xa = -(dif - 2*i);
					ya = -(3*i - dif);
				} else {
					xa = -(4*i - dif + 1);
					ya = dif - 3*i;
				}
			}
			if (!hasFoundB && vet[i] <= B && vet[i+1] > B) {
				hasFoundB = true;
				dif = B-vet[i];
				if (dif <= i) {
					xb = dif;
					yb = i - dif;
				} else if (dif <= 2*i) {
					xb = 2*i - dif;
					yb = -(dif - i);
				} else if (dif <= 3*i) {
					xb = -(dif - 2*i);
					yb = -(3*i - dif);
				} else {
					xb = -(4*i - dif + 1);
					yb = dif - 3*i;
				}
			}
		}
		printf("%.2lf\n", sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb)));
	}
}