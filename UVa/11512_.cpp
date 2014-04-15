#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 1010
#define BASE 5ULL
typedef unsigned long long ull;

int ID[200];
ull B[maxn], HASH[maxn];
char P[maxn];
int n;

set<ull> S;
map<ull, int> M;
set<string> SS;
bool test(int k) {
	S.clear();
	ull temp;
	for (int i = 0; i <= n-k; i++) {
		temp = HASH[i+k] - HASH[i]*B[k];
		if (S.count(temp) > 0) return 1;
		S.insert(temp);
	}
	return 0;
}

char menor[maxn];
int main() {
	ID['A'] = 1, ID['C'] = 2, ID['G'] = 3, ID['T'] = 4;
	B[0] = 1;
	fr(i,1,1001) B[i] = B[i-1]*BASE;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", P);
		n = strlen(P);
		HASH[0] = 0;
		rp(i,n) HASH[i+1] = HASH[i]*BASE + ID[P[i]];
		int ini = 0, fim = n-1, meio;
		while (ini < fim) {
			meio = (ini+fim+1)>>1;
			if (test(meio)) ini = meio;
			else fim = meio-1;
		}
		if (!ini) printf("No repetitions found!\n");
		else {
			M.clear();
			ull temp;
			int k = ini;
			menor[0] = 'Z';
			menor[1] = '\0';
			ull best = 0;
			for (int i = 0; i <= n-k; i++) {
				temp = HASH[i+k] - HASH[i]*B[k];
				if (M[temp] > 0) {
					char rep = P[i+k]; P[i+k] = '\0';
					if (strcmp(P+i,menor) < 0) {
						best = temp;
						//printf("%llu %d %d %c\n", temp, k, i, P[i]);
						rp(j,k) menor[j] = P[i+j];
						menor[k] = '\0';
					}
					P[i+k] = rep;
				}
				M[temp]++;
			}
			printf("%s %d\n", menor, M[best]);
		}
	}
	return 0;
}
