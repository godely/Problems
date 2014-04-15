#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) cerr <<#x"=="<<x<<endl;
#define _ << "," <<
#define pb push_back
#define mp make_pair
#define MAXN 100

using namespace std;

int main() {
	int T, cas = 1;
	long long x1, y1, x2, y2;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

		long long N1 = x1+y1;
		long long N2 = x2+y2;
		long long F = ((N2+1)*N2)/2 - ((N1+1)*N1)/2 - x1 + x2;
		printf("Case %d: %lld\n", cas++, F);
	}
	return 0;
}
