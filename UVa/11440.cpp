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
#define Rp(a,b) Fr(a,0,b)
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

#define dbg if(0)
#define MOD 100000007LL
#define maxp 10000010

bool prime[maxp];
ll resp[maxp];

void sieve() {
	memset(prime,0,sizeof prime);
	prime[2] = 1;
	for (int i = 3; i <= maxp; i+=2) prime[i] = 1;
	for (int i = 3; i <= 10000; i+=2) {
		if (prime[i]) {
			for (int j = i*i; j <= maxp; j+=i) prime[j] = 0;
		}
	}
}

int main() {
	sieve();
	int n, m;
	n=m=10000000;
	resp[1]=1;
	for (ll i = 2; i <= n; i++) {
		if(prime[i]) resp[i] = (resp[i-1]*(i-1LL))%MOD;
		else resp[i] = (resp[i-1]*i)%MOD;
	}
	while (scanf("%d%d", &n, &m) == 2 && n > 0) {
		ll res = resp[m];
		for (ll i = m+1; i <= n; i++) {
			res = (res*i)%MOD;
		}
		printf("%lld\n",(res+MOD-1LL)%MOD);
	}
	
	return 0;
}