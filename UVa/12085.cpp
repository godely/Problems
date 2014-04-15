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

void printRange(ll a, ll b) {
	if (a == b) printf("0%lld\n", a);
	else {
		ll q = 10;
		ll i = a, j = b;
		while (i > 0) {
			i /= 10; j /= 10;
			if (i == j) {
				printf("0%lld-%lld\n", a, b%q);
				break;
			}
			q *= 10;
		}
	}
}

int n;
ll x, y;
int main() {
	int cas = 1;
	while (scanf("%d", &n) == 1 && n > 0) {
		printf("Case %d:\n", cas++);
		scanf("%lld", &x);
		ll first = x;
		y = x;
		Fr(i,1,n) {
			scanf("%lld", &y);
			if (y != x+1) {
				printRange(first,x);
				first = y;
			}
			x = y;
		}
		printRange(first,y);
		printf("\n");
	}
	return 0;
}