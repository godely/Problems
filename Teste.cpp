#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

#define inf 0x3f3f3f3f
#define min(a,b) a<b ? a : b

typedef long long ll;
typedef vector<int> vi;

bitset<10000010> bs;
vi primes;

void crivo(ll upperbound)
{
	ll size = upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	primes.push_back(2);
	for(ll i=4; i<= size; i+=2) bs[i] = 0;
	
	for(ll i=3; i<=size; i+=2)
	{
		if(bs[i])
		{
			primes.push_back((int)i);
			for(ll j= i*i; j<=size; j+=i) bs[j] =0;	
		}
	}
}

vi primeFactors(ll n)
{
	vi factors;
	ll pf_index =0, pf = primes[pf_index];
	while(n!=1 && (pf*pf <= n))
	{
		while(n%pf ==0)
		{
			n/=pf;
			factors.push_back(pf);		
		}
		
		pf = primes[++pf_index];
	
	}
	
	if(n!=1) factors.push_back(n);
	return factors;


}

int main()
{
	crivo(10000000);
	int t,caso=1;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&m, &n);
		
		vi factors = primeFactors((long long)m);
		long long ans=inf;
		for(int i=0; i< (int)factors.size(); i++)
		{
			int val = factors[i];
			int cont=0;
			while(i < (int)factors.size() && factors[i] == val){cont++;i++;}
			int aux = n;
			int resp=0;
			while(aux >= val)
			{
				resp+= aux/val;
				aux/=val;		
			}
			
			ans = min(ans,resp/cont);
			i--;
		}
		printf("Case %d:\n",caso++);
		if(ans ==0) printf("Impossible to divide\n");
		else printf("%d\n",ans);
		

	}
	return 0;
}