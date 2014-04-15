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

#define N 1010

int n, pd[N];
int t;

int main() {
	memset(pd,-1,sizeof pd);
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		if(~pd[n]) printf("%d\n",pd[n]);
		else {
			pd[n]=INF;
			Fr(i,1,(n>>1)+2) if(!(n%i)){
				int tmp=n/i;
				Fr(j,1,(tmp>>1)+2) if(!(tmp%j)){
					int k = tmp/j;
					pd[n] = min(pd[n], (i*j + i*k + j*k)<<1);
				}
			}
			printf("%d\n",pd[n]);
		}
	}
	return 0;
}