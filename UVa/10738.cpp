#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXN 1000100

using namespace std;

int vet[MAXN];
void crivo(){
    for(int i=0;i<MAXN;i++) vet[i]=1;
    for(int i=2;i<MAXN;i+=2) vet[i]=2;
    for(long long i=3;i<MAXN;i+=2){
        if( vet[i] == 1 ) for(long long j=i ; j < MAXN ; j+=i ) vet[j]=i;
    }
}

int mu[MAXN], M[MAXN];
int main() {
	crivo();
	int aux, count, last;
	mu[1] = 1;
	M[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		aux = i;
		count = 0;
		last = -1;
		while (aux > 1) {
			//printf("%d %d %d %d\n", i, aux, vet[aux], last);
			if (vet[aux] == last) {
				mu[i] = 0;
				goto lol;
			}
			last = vet[aux];
			aux = aux/vet[aux];
			count++;
		}
		if (count&1) mu[i] = -1;
		else mu[i] = 1;
		lol:
		M[i] = mu[i] + M[i-1];
	}

	int N;
	while (scanf("%d", &N) == 1 && N > 0) {
		printf("%8d%8d%8d\n", N, mu[N], M[N]);
	}
	return 0;
}
