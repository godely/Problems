#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)

using namespace std;
typedef long long ll;

int pri[1000], qtd=0;
ll A, B, k;
//map<ll,int> mapa;

ll rsp = 0LL;
void back(int p, ll val, bool par){
	if(p == qtd || val*pri[p] > A+B) return;
	
	ll tmp = val*pri[p];
	ll calc = (A+B)/tmp - (A)/tmp;	
	
	if(par) rsp += calc;
	else rsp -= calc;
	
	back(p+1,val*pri[p],!par);
	back(p+1,val,par);
}

int main(){
	cin >> A >> B >> k;
	qtd=0;
	ll tmp = 0LL;
	fr(i,2,k+2){
		bool pr = true;
		fr(j,2,i){
			if(i%j==0) pr = false;
		}
		if(pr){
			if(i<=A+B && i > A) tmp++;
			pri[qtd++] = i;
		}
	}
	
	rsp = 0LL;
	back(0,1LL,0);
	cout << B + rsp + tmp << endl;
	
	return 0;
}
