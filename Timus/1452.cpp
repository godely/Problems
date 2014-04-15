//by stor
#include <cstdio>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define MAXN 2001

using namespace std;

int fila[MAXN*(MAXN/2)+10];
short fila2[MAXN*(MAXN/2)+10];
int front[MAXN], size[MAXN];

struct abc {
	int val, ind;
	abc() {}
	abc(int val, int ind) : val(val), ind(ind) {}
	
	bool operator<(const abc &lhs) const {
		return val < lhs.val;
	}
	bool operator==(const abc &lhs) const {
		return val == lhs.val;
	}
} vet[MAXN];

int main() {
	int N, k, maxTam = 0, maxRazao, maxInit;
	scanf("%d", &N);
	rp(i,N) scanf("%d", &vet[i].val), vet[i].ind = i+1;
	sort(vet, vet+N);
	N = unique(vet, vet+N) - vet;
	front[0]=size[0]=0;
	fr(i,1,N) front[i]=size[i]=(size[i-1]+N-i);

	for (int i = N-2; i >= 0; i--) {
		for (int j = i+1; j < N; j++) {
			k = vet[j].val-vet[i].val;
			//printf("%d %d %d\n", i, j, k);
			while (front[j] < size[j] && fila[front[j]] < k) front[j]++;
			if (front[j] < size[j] && fila[front[j]] == k) fila[size[i]] = k, fila2[size[i]] = fila2[front[j]]+1, front[j]++;
			else fila[size[i]] = k, fila2[size[i]] = 2;
			size[i]++;

			if (fila2[size[i]-1] > maxTam) {
				maxTam = fila2[size[i]-1];
				maxRazao = fila[size[i]-1];
				maxInit = i;
			}
		}
	}
	if (maxTam == 0) printf("1\n1\n");
	else {
		printf("%d\n", maxTam);
		k = vet[maxInit].val;
		for (int i = maxInit; i < N && maxTam > 0; i++) {
			if (vet[i].val == k) {
				maxTam--;
				maxTam > 0 ? printf("%d ", vet[i].ind) : printf("%d", vet[i].ind);
				k += maxRazao;
			}
		}
		printf("\n");
	}
	return 0;
}