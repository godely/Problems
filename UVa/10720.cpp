#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define pb push_back

using namespace std;

int vet[10001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, sum, sum2;
	while (scanf("%d", &n) == 1 && n) {
		sum = 0;
		rp(i,n) scanf("%d", &vet[i]), sum+=vet[i];
		sort(vet,vet+n,cmp);
		if (sum&1) printf("Not possible\n");
		else {
			sum = 0;
			fr(k,1,n+1) {
				sum += vet[k-1];
				sum2 = 0;
				fr(i,k+1,n+1) sum2 += min(vet[i-1],k);
				//printf("%d %d %d\n", sum, k*(k-1), sum2);
				if (sum > k*(k-1) + sum2) {
					printf("Not possible\n");
					goto lol;
				}
			}
			printf("Possible\n");
		}
		lol:;
	}
	return 0;
}