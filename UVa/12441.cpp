#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define oo 0x3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
#define MOD 1000000007

char A[500], B[500], C[500];
int szA, szB, szC;
int mark[101][101][301], passo;
pii dp[101][101][301];
int next[500][300];

pii go(int a, int b, int c) {
	pii &pd = dp[a][b][c];
	if (mark[a][b][c] == passo) return pd;
	mark[a][b][c] = passo;
	if (c >= szC+1) return pd = pii(oo,0);
	else if (a >= szA && b >= szB) return pd = pii(0,1);
	else if (c >= szC) return pd = pii(oo,0);
	pii res;
	if (a >= szA) {
		res = go(a,b+1,next[c][B[b]]+1);
		res.F++;
	} else if (b >= szB) {
		res = go(a+1,b,next[c][A[a]]+1);
		res.F++;
	} else {
		if (A[a] == B[b]) {
			res = go(a+1,b+1,next[c][A[a]]+1);
			res.F++;
		} else {
			pii aux1 = go(a+1,b,next[c][A[a]]+1);
			pii aux2 = go(a,b+1,next[c][B[b]]+1);
			aux1.F++; aux2.F++;
			res = aux1;
			if (aux1.F > aux2.F) res = aux2;
			else if (aux1.F == aux2.F) res.S=(res.S+aux2.S)%MOD;
		}
	}
	return pd = res;
}

char str[500];
int k;

void bt(int a, int b, int c) {
	if (a >= szA && b >= szB) {
		str[k] = 0;
		return;
	}

	if (a >= szA) {
		str[k++] = B[b];
		bt(a,b+1,next[c][B[b]]+1);
	} else if (b >= szB) {
		str[k++] = A[a];
		bt(a+1,b,next[c][A[a]]+1);
	} else {
		if (A[a] == B[b]) {
			str[k++] = A[a];
			bt(a+1,b+1,next[c][A[a]]+1);
		} else {
			int aux1 = 1 + dp[a+1][b][next[c][A[a]]+1].F;
			int aux2 = 1 + dp[a][b+1][next[c][B[b]]+1].F;
			if (aux1 == aux2) {
				if (A[a] < B[b]) {
					str[k++] = A[a];
					bt(a+1,b,next[c][A[a]]+1);
				} else {
					str[k++] = B[b];
					bt(a,b+1,next[c][B[b]]+1);
				}
			} else {
				if (aux1 < aux2) {
					str[k++] = A[a];
					bt(a+1,b,next[c][A[a]]+1);
				} else {
					str[k++] = B[b];
					bt(a,b+1,next[c][B[b]]+1);
				}
			}
		}
	}
}

int main() {
	passo = 0;
	cl(mark,0);
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s%s", A, B, C);
		szA = strlen(A);
		szB = strlen(B);
		szC = strlen(C);
		rp(i,szC) {
			rp(j,300) next[i][j] = szC+1;
			fr(j,i,szC) if (j < next[i][C[j]]) next[i][C[j]] = j;
		}
		passo++;
		pii aux = go(0,0,0);
		if (aux.F >= oo) aux.S = 0;
		printf("Case %d: %d\n", cas++, aux.S);
		if (aux.F < oo) {
			k = 0; bt(0,0,0);
			printf("%s\n", str);
		} else {
			printf("NOT FOUND\n");
		}
	}
	return 0;
}