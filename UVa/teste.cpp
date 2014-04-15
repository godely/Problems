//

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
#define mod 1000000007LL

int n, k;

struct matriz {
	ll mat[2][2];
	matriz() {}
	matriz(ll a, ll b, ll c, ll d) {
		mat[0][0] = a, mat[0][1] = b, mat[1][0] = c, mat[1][1] = d;
	}
	
	matriz operator*(const matriz &lhs) const {
		matriz ret = matriz();
		Fr(i,0,2) Fr(j,0,2) {
			ret.mat[i][j] = 0;
			Fr(k,0,2) ret.mat[i][j] = (ret.mat[i][j] + mat[i][k]*lhs.mat[k][j])%mod;
		}
		return ret;
	}
} aux, res;

void fastExp(int N) {
	for (; N > 0; N >>= 1, aux = aux*aux) if (N&1) res = res*aux;
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		ll resp=0;
		if(n==1) resp = 1;
		else if(n==2) resp=4;
		else {
			aux = matriz(2,1,0,2);
			res = matriz(1,0,0,1);
			fastExp(n-1);
			resp = (res.mat[0][0]+(res.mat[0][1]<<1))%mod;
		}
		printf("Case #%d: %lld\n",cas++, resp);
	}
	return 0;
}