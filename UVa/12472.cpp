#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define INF 1111111111111111LL

using namespace std;

long long A, B;

long long solve(long long P, long long M) {
	if (P > B) return INF;

	long long comp = A&M;
	if (comp == P) return A;

	int i;
	for (i = 0; i <= 50; i++) if (1LL<<i > P) break;
	long long newA;
	if (comp < P)	newA = (A>>i)<<i;
	else 			newA = (((A>>i)+1)<<i);

	long long ret = newA|P;
	if (ret > B)	return solve(P<<1, M<<1);
	else			return min(ret, solve(P<<1, M<<1));
}

int main() {
	int T, cas = 1;
	long long P, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &A, &B, &P);
		for (int i = 0; i <= 50; i++) {
			M = 1LL<<i;
			if (M > P) {
				M--;
				break;
			}
		}
		long long res = solve(P,M);
		if (res == INF)
			printf("Case %d: NONE\n", cas++);
		else
			printf("Case %d: %lld\n", cas++, res);
	}
}
