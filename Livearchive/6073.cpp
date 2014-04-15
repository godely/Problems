#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MOD 1000000007
typedef long long ll;

int N, M, K;
int C, Q;
int s[1<<11], p[10010], m[20], n[20];
int mark[1010][110][1<<4], passo;

ll dp[1010][110][1<<4];
int COMPL, LIM;

ll go(int sum, int k, int msk) {
	ll &pd = dp[sum][k][msk];
	if (mark[sum][k][msk] == passo) return pd;
	mark[sum][k][msk] = passo;
	if (k == 0) return pd = (sum == 0 && msk == COMPL);
	else if (sum == 0) return pd = 0;


	//printf("%d %d %d\n", sum, k, msk);
	ll res = go(sum-1,k-1,msk);
	fr(i,1,C) if (s[i] <= sum) res = (res+go(sum-s[i],k-1,msk|p[s[i]]))%MOD;
	return pd = res;
}

int main() {
	passo = 0;
	while (scanf("%d%d%d", &N, &M, &K) == 3) {
		int M_ = M;
		C = Q = 0;
		fr(i,2,M+1) {
			if (M_%i == 0) {
				int fat = 1;
				while (M_%i == 0) {
					M_/=i;
					m[C++] = i;
					fat*=i;
				}
				n[Q++] = fat;
			}
		}
		LIM = (1<<C);
		COMPL = (1<<Q)-1;
		s[0] = 0;
		cl(p,0);
		fr(i,1,LIM) {
			s[i] = 1;
			rp(j,C) if ((i>>j)&1) s[i] *= m[j];
			rp(j,Q) if (s[i]%n[j] == 0) p[s[i]]|=(1<<j);
		}
		sort(s,s+LIM);
		C = unique(s,s+LIM) - s;
		//fr(i,1,C) printf("%d (%d)\n", s[i], p[s[i]]);
		passo++;
		printf("%lld\n", go(N,K,0));
	}
}