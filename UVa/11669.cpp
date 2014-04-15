#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define MAXN 1000001

bool prm[MAXN+10];
int prime[MAXN+10], np;
int fat[MAXN+10];
int bucket[1010][1010];

void sieve() {
	cl(prm,1);
	prm[0] = prm[1] = 0;
	for (int i = 4; i <= MAXN; i+=2) prm[i] = 0, fat[i] = 2;
	for (int i = 3; i <= 1000; i+=2) {
		if (prm[i]) {
			for (int j = i*i; j <= MAXN; j+=i) {
				if (prm[j]) prm[j] = 0, fat[j] = i;
			}
		}
	}
	np = 0;
	rp(i,MAXN) {
		if (prm[i]) prime[np++] = i, fat[i] = i;
	}
}

int deep;
int seq[MAXN*10], sz = 0;
void bt(int p, int d, ll m) {
	if (d == deep) {
		if(m < MAXN) seq[sz++] = m;
	} else {
		for (; p < np; p++) {
			if (m*prime[p] <= MAXN) bt(p, d+1, m*prime[p]);
			else break;
		}
	}
}

int main() {
	sieve();
	for (deep = 1; deep <= 19; deep++) bt(0,0,1);

	int sq = 1000;
	rp(i,sq) {
		rp(j,sq) {
			if (i*sq+j < sz) bucket[i][j] = seq[i*sq+j];
			else bucket[i][j] = 1000001;
		}
		sort(bucket[i],bucket[i]+sq);
	}

	int T, A, B, K, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &A, &B, &K);
		int i = 0;
		for (; i < sq; i++) {
			int x = upper_bound(bucket[i], bucket[i]+sq, B) - lower_bound(bucket[i], bucket[i]+sq, A);
			if (K - x > 0) K-=x;
			else {
				for (i = i*sq; i < sz && K; i++) if (seq[i] >= A && seq[i] <= B) K--;
				i--;
				break;
			}
		}
		printf("Case %d:", cas++);
		int p = seq[i];
		while (p > 1) {
			printf(" %d", fat[p]);
			p/=fat[p];
		}
		puts("");
	}
}