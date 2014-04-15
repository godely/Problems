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
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 10000000000007LL

using namespace std;

int n, m, x;
int main() {
	scanf("%d%d%d", &n, &m, &x); x--;
	if (n > m) swap(n,m);
	for (int i = 0; i < x && n > 0; i++) {
		//printf("%d\n", cur);
		n-=2;
		m-=2;
	}
	if (n <= 0) printf("0\n");
	else if (n == 1) printf("%d\n", (m+1)>>1);
	else printf("%d\n", n+m-2);
	return 0;
}
/* Compile Error:
 30956 */