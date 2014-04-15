#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define maxn 110000

int SA[maxn], RA[maxn], tempSA[maxn], tempRA[maxn], Phi[maxn], LCP[maxn], PLCP[maxn];
int C[40], rep[maxn], c[maxn];
char T[maxn];
int n, m;

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	fr(i,1,n) Phi[SA[i]] = SA[i-1];
	for (i = L = 0; i < n; i++) {
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }
		while (T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
}

void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++) c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for (i = 0; i < n; i++) SA[i] = tempSA[i];
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for (i = 0; i < n; i++) RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;
	}
	computeLCP();
}

multiset<int> ms;
int main() {
	int _, K;
	scanf("%d", &_);
	while (_--) {
		ms.clear();
		scanf("%d", &K);
		n = 0;
		rp(i,K) {
			scanf("%s", T+n);
			m = n+strlen(T+n);
			fr(j,n,m) rep[j] = i;
			n = m;
			T[n++] = 32+i;
		}
		if (K == 1) {
			printf("%d\n", n-1);
			continue;
		}
		constructSA();
		cl(C,0);
		int ans = 0;
		for (int i = K, j = K, cnt = 0; j < n; i++) {
			while (cnt < K && j < n) {
				ms.insert(LCP[j]);
				C[rep[SA[j]]]++;
				if (C[rep[SA[j]]] == 1) cnt++;
				j++;
			}
			C[rep[SA[i]]]--;
			if (C[rep[SA[i]]] == 0) cnt--;
			ms.erase(ms.find(LCP[i]));
			ans = max(ans,*ms.begin());
		}
		printf("%d\n", ans);
	}
	return 0;
}