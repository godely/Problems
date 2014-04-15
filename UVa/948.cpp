#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int F[50], T, N, M;
int main() {
	//F[0]=0;
	F[0]=1;
	F[1]=2;
	for (int i=2; i <= 40; i++) {
		F[i] = F[i-1]+F[i-2];
	}
	scanf("%d", &T);
	while (T--) {
		bool pd = true;
		scanf("%d", &N);
		printf("%d = ", N);
		int i;
		for (i = 40; i >= 0 && N < F[i]; i--);
		for (; i >= 0; i--) {
			if (N >= F[i] && pd) {
				//printf("%d %d\n", F[i], N);
				printf("1");
				N-=F[i];
				pd = false;
			} else {
				printf("0");
				pd = true;
			}
		}
		printf(" (fib)\n");
	}
	return 0;
}
