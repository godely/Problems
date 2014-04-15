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
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define cl(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define maxn 11000

ll M, N;
ll a,b,d,cnt[11]; 
ll C(ll x) {
	cl(cnt,0);
	if (x < 0) return -1;
    ll k = 1; 
    ll l=x; 
    while(x) { 
        a=x/10; 
        b=x%10; 
        d=l%k; 
  
        for (int i=0; i<b;i++) cnt[i]+=k*(a+(i?1:0)); 
        cnt[b]+=k*(a-(b?0:1))+d+1; 
        for (int i=b+1; i<10; i++) cnt[i]+=k*a; 
  
        k*=10; 
        x/=10; 
    }
    return cnt[0];
}

int main() {
	while (scanf("%lld%lld", &M, &N) == 2 && M >= 0) {
		printf("%lld\n", C(N) - C(M-1));
	}
}