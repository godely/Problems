#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 3000
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
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

char *antigo;
int main(){
	bool ok = 0;
	int size1;
	while (gets(T)) {
		if (ok) printf("\n");
		else ok = 1;
		n = strlen(T);
		size1 = n;
		T[n++]='.';
		gets(T+n);
		n = strlen(T);
		constructSA();
		computeLCP();
		int maxLCP = 0, a, b;
		for(int i = 1; i < n; i++) {
			a = SA[i] < size1;
			b = SA[i-1] > size1;
			if ((a&&b || !a&&!b) && LCP[i] > maxLCP) maxLCP = LCP[i];
		}
		char temp;
		antigo = T+n;
		if (maxLCP > 0) {
			for (int i = 1; i < n; i++) {
				a = SA[i] < size1;
				b = SA[i-1] > size1;
				if ((a&&b || !a&&!b) && LCP[i] == maxLCP && strncmp(T+SA[i],antigo,maxLCP)!=0) {
					temp = T[SA[i]+maxLCP];
					T[SA[i]+maxLCP]='\0';
					antigo = T+SA[i];
					printf("%s\n", antigo);
					T[SA[i]+maxLCP]=temp;
				}
			}
		} else printf("No common sequence.\n");
		getchar();
	}
	return 0;
}