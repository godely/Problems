//bgcr
#include <bits/stdc++.h>
using namespace std;
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) cerr << #x " == " << x << endl;
#define ll long long
ll a,b,c;
ll solve(ll n){
	if(!n) return a;
	else if(n==1) return b;
	else if(n==2) return (1+b)/a;
	else if(n==3) return (a+b+1)/(a*b);
	else return (a+1)/(b);
}
int main(){
	while(scanf("%lld%lld%lld",&a,&b,&c)>0&&(a||b||c)) printf("%lld\n",solve(c%5));
	return 0;
}
