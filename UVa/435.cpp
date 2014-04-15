#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int P, sum;
int ind_[22], vet[22];
void bt(int ind, int mask, int partial) {
	if (ind >= P) {
		rp(i,P) {
			if (!((1<<i)&mask) && partial+vet[i] > sum) ind_[i]++;
		}
		return;
	}
	bt(ind+1,mask,partial);
	if (partial+vet[ind] <= sum) bt(ind+1,mask|(1<<ind),partial+vet[ind]);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &P);
		sum = 0;
		memset(ind_,0, sizeof ind_);
		rp(i,P) scanf("%d", &vet[i]), sum+=vet[i];
		sum/=2;
		bt(0,0,0);
		rp(i,P) printf("party %d has power index %d\n", i+1, ind_[i]);
		printf("\n");
	}
}