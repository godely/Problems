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

int main(){
	int cas;
	scanf("%d\n", &cas);
	while (cas--) {
		gets(T);
		n = strlen(T);
		T[n++]='.';
		T[n]='\0';
		constructSA();
		computeLCP();
		int maxLCP = 0, maxCombo = 0, ind;
		bool going = 0;
		for(int i = 1; i < n; i++) {
			if (LCP[i] > maxLCP) {
				maxCombo = 2;
				maxLCP = LCP[i];
				ind = SA[i];
				going = 1;
			} else if (LCP[i] == maxLCP && going) {
				maxCombo++;
			} else going = 0;
		}
		if (maxLCP) {
			T[ind+maxLCP]='\0';
			printf("%s %d\n", T+ind, maxCombo);
		} else printf("No repetitions found!\n");
	}
	return 0;
}