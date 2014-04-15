#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)

using namespace std;
typedef long long ll;
#define N 100100
char g[N][6];
int g2[N];
int n;
int cod(char a){
	if(a >= '0' && a <= '9') return a-'0';
	return a-'a'+10;
}
ll func(int msk){
	rep(i,n){
		g2[i] = 0;
		rep(j,4){
			if((1<<j)&msk){
				g2[i] |= cod(g[i][j])<<(j*4);
			}
		}
	}
	sort(g2,g2+n);
	ll r = 0, tam=0;
	rep(i,n){
		tam++;
		if(i==n-1 || g2[i+1] != g2[i]){
			r += (tam*(tam-1))/2LL;
			tam = 0;
		}
	}
	return r;
}

int count(int m){
	int r = 0;
	while(m){
		if(m&1) r++;
		m>>=1;
	}
	return r;
}

ll r[10], tot[10];

int main(){

	scanf("%d",&n);
	rep(i,n){
		scanf("%s",g[i]);		
	}
	
	fr(i,1,16){
		tot[count(i)] += func(i);
	}
	r[0] = tot[4];
	r[1] = tot[3] - 4*r[0];
	r[2] = tot[2] - 6*r[0] - 3*r[1];
	r[3] = tot[1] - 4*r[0] - 3*r[1] - 2*r[2];
	r[4] = (ll(n)*(n-1)/2LL) - r[0] - r[1] - r[2] - r[3];
	fr(i,1,5){
		if(i!=1) cout << " ";
		cout << r[i];
	}
	cout << endl;
	
	return 0;
}