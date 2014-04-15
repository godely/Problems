#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
using namespace std;

int chg(int *A, int a, int b, int c, int d) {
	int aux = A[a];
	A[a] = A[b];
	A[b] = A[c];
	A[c] = A[d];
	A[d] = aux;
}

void rot(int *A, int type, int dir) {
	if (type == 0) {
		if (dir==1) chg(A,1,0,3,4);
		else chg(A,1,4,3,0);
	} else if (type == 1) {
		if (dir==1) chg(A,2,1,4,5);
		else chg(A,2,5,4,1);
	} else if (type == 2) {
		if (dir == 1) chg(A,4,3,6,7);
		else chg(A,4,7,6,3);
	} else {
		if (dir == 1) chg(A,5,4,7,8);
		else chg(A,5,8,7,4);
	}
}

void unhash(int *A, ll aux) {	
	int p = 8;
	while (~p) A[p--] = aux%10, aux/=10;
}

ll hash(int *A) {
	ll ret = 0;
	rp(i,9) ret*=10, ret+=A[i];
	return ret;
}

map<ll,int> m[2];
int B[15], ini, fim;
ll fila[10000000];
int bfs(ll first, int k, int w = 1) {
	m[w].clear();
	ll aux;
	int cost;
	ini = fim = 0;
	fila[fim++] = first;
	m[w][first] = 0;
	while (ini < fim) {
		aux = fila[ini++];
		cost = m[w][aux];
		if (w && m[0].count(aux) > 0) {
			if (cost+m[0][aux] <= k) return cost+m[0][aux];
			return -1;
		}
		unhash(B, aux);
		if (cost < k) {
			rp(i,4) {
				rp(j,2) {
					rot(B, i, j);
					if (m[w].count(hash(B)) == 0) {
						m[w][hash(B)] = cost+1;
						fila[fim++] = hash(B);
					}
					rot(B, i, j^1);
				}
			}
		}
	}
	return -1;
}

int main() {
	bfs(123456789LL, 4, 0);
	int cas = 1;
	ll N;
	while (scanf("%lld", &N) == 1 && N > 0) {
		ll n = N%1000000000;
		int k = N/1000000000;
		printf("%d. %d\n", cas++, bfs(n,k));
	}
}