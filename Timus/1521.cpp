#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAXN 100010
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<

int pd[100010];
void inc(int x){
	while(x<MAXN){
		pd[x]++;
		x+=(x&-x);
	}
}
void dec(int x){
	while(x<MAXN){
		pd[x]--;
		x+=(x&-x);
	}
}
int pos(int x){
	int res=0;
	while(x){
		res+=pd[x];
		x-=(x&-x);
	}
	return res;
}
int main(){
	int n, k, j=1, m;
	cin>>n>>k;
	m=n;
	for(int i=1;i<=n;i++)inc(i);
	
	while(m){
		for(int i=1; i<=n; i++) printf("%d ", pos(i));
		printf("\n");
		j = ((j-1+(k-1)+m)%m)+1;
		int a=1, b=n, c;
		
		while(a<b){
			c=(a+b)/2;
			if(pos(c)<j){
				a=c+1;;
			}else {
				b=c;
			}
		}
		m--;
		//printf("%d%s", a, m?" ":"\n");
		dec(a);
	}
	
	return 0;
}