#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

long long POT[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 1000000001};
long long D[20];

void F(int n, int f) {
	int ind = 0;
	while (n%POT[ind] != n) ind++;
	long long k = POT[ind-1], last = 0, d, m = n;
	while (k > 0) {
		d = m/k;
		m = m%k;

		for (int i = 0; i < d; i++) D[i] += f*k*(last + (i>0));
		D[d] += f*(k*(last - 1 + (d>0)) + m + 1);
		for (int i = d+1; i < 10; i++) D[i] += f*k*last;

		last = n/k;
		k /= 10;
	}
}

int main() {
	int A, B;
	memset(D,0,sizeof D);
	long long sum;
	while (scanf("%d%d", &A, &B) == 2 && A > 0) {
		memset(D,0,sizeof D);
		F(B,1); if (A > 1) F(A-1,-1);
		sum = 0;
		for (int i = 1; i <= 9; i++) sum+=(i*D[i]);
		printf("%lld\n", sum);
	}
	return 0;
}