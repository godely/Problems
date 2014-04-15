#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

char m[1<<24];
int sizeM;
int F[1<<24];

void kmp() {
	F[0] = -1;
	F[1] = 0;
	for (int i = 2; i <= sizeM; i++) {
		F[i] = F[i-1];
		while (F[i] >= 0 && m[F[i]+1] != m[i]) {
			F[i] = F[F[i]];
		}
		if (m[F[i]+1] == m[i]) F[i]++;
	}
	//printf("%d\n", sizeM-(F[sizeM-1]+1));
	int k = F[sizeM-1];
	//printf("%d\n", k);
	while (sizeM%(sizeM-(k+1))!=0) {
		k = F[k];
	}
	printf("%d\n", sizeM/(sizeM-(k+1)));
}

int main() {
	while (gets(m)) {
		if (m[0] == '.') break;
		sizeM = strlen(m);
		kmp();
	}
}
