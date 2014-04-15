#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#define limit 4294967296LL

using namespace std;

int main() {
	map<long long, int> mapa;
	long long N, sq, p, count;
	for (long long i = 2; i <= 65536; i++) {
		p = i;
		count=0;
		while (p <= limit) {
			count++;
			if (mapa[p]==0) mapa[p] = count;
			if (mapa[-p]==0 && count&1) mapa[-p] = count;
			p*=i;
		}
	}

	while (scanf("%lld", &N) == 1 && N != 0) {
		if (mapa[N]==0) printf("1\n");
		else printf("%d\n", mapa[N]);
	}
	return 0;
}
