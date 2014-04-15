#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 300010
typedef long long ll;
char T[maxn];
int n, m;
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn];
int Phi[maxn];
int LCP[maxn];
int PLCP[maxn];

void countingSort(int k){
	int i,sum,maxi=max(300,n);
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++) c[i+k<n?RA[i+k]:0]++;
	for(i=sum=0;i<maxi;i++){
		int t=c[i];
		c[i]=sum;
		sum+=t;
	}
	for(i=0;i<n;i++) {
		tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
	}
	for(i=0;i<n;i++) SA[i]=tempSA[i];
}

void constructSA(){
	int i,k,r;
	for(i=0;i<n;i++) RA[i]=T[i]-'.';
	for(i=0;i<n;i++) SA[i]=i;
	for(k=1;k<n;k<<=1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]]=r=0;
		for(i=1;i<n;i++) tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
		for(i=0;i<n;i++) RA[i]=tempRA[i];
	}
}

void computeLCP(){
	int i,L;
	Phi[SA[0]]=-1;
	for(i=1;i<n;i++) Phi[SA[i]]=SA[i-1];
	for(i=L=0;i<n;i++){
		if(Phi[i]==-1){
			PLCP[i]=0;
			continue;
		}
		while(T[i+L]==T[Phi[i]+L]) L++;
		PLCP[i]=L;
		L=max(L-1,0);
	}
	for(i=1;i<n;i++) LCP[i]=PLCP[SA[i]];
}

int main() {
	int cas = 1, _, k;
	scanf("%d", &_);
	while (_--) {
		scanf("%s%d", T, &k);
		m = strlen(T);
		rp(i,m) T[i+m] = T[i];
		n = 2*m;
		T[n++] = '.';
		T[n] = '\0';
		constructSA();
		computeLCP();
		ll s1 = 0;
		fr(i,1,n) s1 += n-1-SA[i]-LCP[i];//, printf("%d %s\n", n-1-SA[i], T+SA[i]);
		
		if (k == 2) printf("Case %d: %lld\n", cas++, s1);
		else {
			rp(i,m) T[i+2*m] = T[i];
			n = 3*m;
			T[n++] = '.';
			T[n] = '\0';
			constructSA();
			computeLCP();
			ll s2 = 0;
			fr(i,1,n) s2 += n-1-SA[i]-LCP[i];//, printf("%d %s\n", n-1-SA[i], T+SA[i]);
			ll dif = (s2-s1);
			printf("Case %d: %lld\n", cas++, s1+(k-2)*(s2-s1));
		}
	}
	return 0;
}