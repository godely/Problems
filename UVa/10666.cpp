#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
long long cas,n,m;
int main(){
	scanf("%lld",&cas);
	while(cas--){
		scanf("%lld%lld",&n,&m);
		long long nivel=0,ini=1;
		long long s = m;
		if (m) while((m&1) == 0) m>>=1, nivel++;
		else nivel=n;

		s = m;
		long long c = 1;
		while (s) {
			if (s&1) c++;
			s>>=1;
		}
		printf("%lld %lld\n", c,(1LL<<n)-(1LL<<(nivel))+1);
	}
	return 0;
}
