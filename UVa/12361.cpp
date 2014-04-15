#include <bits/stdc++.h>
using namespace std;
#define MAX_N 700000
#define inf 0x3f3f3f3f
#define _push(a,b) st[stSize][0] = a, st[stSize][1] = b, stSize++
#define _pop() stSize--
#define _topElem() st[stSize-1][0]
#define _topMask() st[stSize-1][1]
#define _empty() (stSize == 0)
#define _clear() stSize = 0

long long st[3*MAX_N][2], stSize;

char T[MAX_N];
int Y[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N], P[MAX_N];
int TAM[MAX_N];
int Phi[MAX_N];
int LCP[MAX_N];
int PLCP[MAX_N];
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
	for(i=0;i<n;i++) RA[i]=Y[i];
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
		while(Y[i+L]==Y[Phi[i]+L]) L++;
		PLCP[i]=L;
		L=max(L-1,0);
	}
	for(i=1;i<n;i++) LCP[i]=PLCP[SA[i]];
}

set<long long> SET;
int size;
int main(){
	int N;
	int g;
	while (scanf("%d", &N)==1 && N > 0) {
		n = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s", T+n);
			size = strlen(T+n);
			n+=size;
			if (i < N-1) T[n++]='.';
		}
		g = 1;
		for (int i = 0; i < n; i++) Y[i] = (T[i] == '.') ? g++ : T[i]-'a' + 105;
		constructSA();
		computeLCP();
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (Y[i] < 100) P[i]=-1, count++;
			else P[i] = count;
		}
		int count2 = 1;
		for (int i = n-1; i >= 0; i--) {
			if (Y[i] < 100) TAM[i] = -1, count2 = 1;
			else TAM[i] = count2++;
		}
		
		printf("SA	TAM	LCP	P\n");
		for (int i = count; i < n; i++) {
			printf("%2d	%2d	%2d	%2d		%s\n", SA[i], TAM[SA[i]], LCP[i], P[SA[i]], T+SA[i]);
		}
		
		_clear();
		SET.clear();
		long long tempMask;
		for (int i = count; i < n; i++) {
			tempMask = 0;
			//printf("%s:\n", T+SA[i]);
			while (!_empty() && _topElem() > LCP[i]) {
				tempMask |= _topMask();
				if (SET.find(tempMask) == SET.end());
				SET.insert(tempMask);
				_pop();
			}
			if (_empty()) {
				for (int j = 1; j <= TAM[SA[i]]; j++) _push(j, (1LL<<P[SA[i]]));
			} else {
				if (LCP[i] == _topElem()) {
					//printf("	3!\n");
					tempMask = _topMask()|(1LL<<P[SA[i]]);
					_pop();
					_push(LCP[i], tempMask);
				}
				for (int j = LCP[i]+1; j <= TAM[SA[i]]; j++) _push(j, (1LL<<P[SA[i]]));
			}
			//printf("\n");
		}
		tempMask = 0;
		while (!_empty() && _topElem() > 0) {
			tempMask |= _topMask();
			SET.insert(tempMask);
			_pop();
		}
		printf("%d\n", SET.size());
	}
	return 0;
}