#include <bits/stdc++.h>
using namespace std;
#define MAX_N 300000
#define inf 0x3f3f3f3f
char T[MAX_N];
int Y[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N], P[MAX_N];
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

char *last;
map<int,int> B;
int res[MAX_N], sizeRes;
int size;
int main(){
	bool ok = 0;
	int N;
	int g;
	while (scanf("%d", &N)==1 && N > 0) {
		if (ok) printf("\n");
		else ok = 1;
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
		/*printf("SA	LCP	P\n");
		for (int i = count; i < n; i++) {
			printf("%2d	%2d	%2d		%s\n", SA[i], LCP[i], P[SA[i]], T+SA[i]);
		}*/
		B.clear();
		int i = 2, j = 2, limiar=N/2;
		B[P[SA[i]]]++;
		int maxLCP=0, tempLCP;
		sizeRes=0;
		while (1) {
			if (B.size() > limiar) {
				tempLCP=inf;
				for (int a = i+1; a <= j; a++) tempLCP=min(tempLCP,LCP[a]);
				if (tempLCP < inf && tempLCP > maxLCP) {
					maxLCP = tempLCP;
					res[0] = SA[i];
					sizeRes = 1;
				} else if (tempLCP > 0 && tempLCP == maxLCP) res[sizeRes++] = SA[i];
				(B[P[SA[i]]]>1) ? B[P[SA[i++]]]-- : B.erase(P[SA[i++]]);
			} else if (j < n-1) j++, B[P[SA[j]]]++;
			else break;
		}
		if (sizeRes==0) printf("?\n");
		else {
			char temp = T[res[0]+maxLCP];
			T[res[0]+maxLCP] = '\0';
			printf("%s\n", T+res[0]);
			T[res[0]+maxLCP]=temp;
			last = T + res[0];
			for (int i = 1; i < sizeRes; i++) {
				if (strncmp(last, T+res[i], maxLCP) == 0) continue;
				temp = T[res[i]+maxLCP];
				T[res[i]+maxLCP]='\0';
				printf("%s\n", T+res[i]);
				T[res[i]+maxLCP]=temp;
				last = T + res[i];
			}
		}
	}
	return 0;
}