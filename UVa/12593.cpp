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
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
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
#define mod 10007

int n, k;
int aux[110][110], mat[110][110], ret[110][110];

void mult1() {
	Fr(i,0,k) Fr(j,0,k) {
		ret[i][j] = 0;
		Fr(q,0,k) ret[i][j] = (ret[i][j]+mat[i][q]*mat[q][j])%mod;
	}
	Fr(i,0,k) Fr(j,0,k) mat[i][j] = ret[i][j];
}

void mult2() {
	Fr(i,0,k) Fr(j,0,k) {
		ret[i][j] = 0;
		Fr(q,0,k) ret[i][j] = (ret[i][j]+aux[i][q]*mat[q][j])%mod;
	}
	Fr(i,0,k) Fr(j,0,k) aux[i][j] = ret[i][j];
}

void print1() {
	Fr(i,0,k) {
		Fr(j,0,k) {
			printf("%d ", aux[i][j]);
		}
		printf("\n");
	}
}

void print2() {
	Fr(i,0,k) {
		Fr(j,0,k) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
//	cin.sync_with_stdio(false);
	int T; scanf("%d", &T);
	Fr(cas,1,T+1) {
		scanf("%d%d", &n, &k); n--;
		memset(mat,0,sizeof mat); memset(aux,0,sizeof aux);
		Fr(i,0,k-1) {
			mat[i][i+1] = 1;
			aux[i][i] = 1;
		}
		aux[k-1][k-1] = 1;
		Fr(i,0,k-1) mat[k-1][i] = 1;
		//print1();
		//printf("\n");
		//print2();
		for (; n; n >>= 1, mult1()) {
			if (n&1) mult2();
		}
		int cont = 0;
		Fr(i,0,k) cont = (cont+aux[i][k-1])%mod;//, printf("%d\n", aux[i][k-1]);
		cont = (cont*2)%mod;
		printf("Case %d: %d\n", cas, cont);
	}
	return 0;
}