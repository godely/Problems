#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define pb push_back

using namespace std;

int T, N, M;
int A[1001], B[1001], mat[1001];

int main() {
	scanf("%d", &T);
	int aux, maximo;
	while (T--) {
		scanf("%d", &N);
		rp(i,N) scanf("%d", &A[i]);
		scanf("%d", &M);
		rp(i,M) scanf("%d", &B[i]), mat[i] = 0;
		maximo = 0;
		rp(i,N) {
			aux = 0;
			rp(j,M) {
				if (A[i]==B[j] && 1+aux > mat[j]) mat[j] = 1+aux, maximo = max(maximo,mat[j]);
				else if (A[i]>B[j]) aux = max(aux, mat[j]);
			}
		}
		printf("%d\n", maximo);
	}
	return 0;
}