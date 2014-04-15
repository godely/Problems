#include <bits/stdc++.h>
using namespace std;

double sqr(double a){ return a*a; }

int main(){
	int cas,n;
	scanf("%d",&cas);
	double r2=sqrt(2.0);
	while(cas--){
		scanf("%d",&n);
		if (n==1) printf("0.000\n");
		else printf("%.3lf\n",sqr(double(n-2))*r2+(sqr(double(n))-sqr(double(n-2))));
		if(cas) printf("\n");
	}
	return 0;
}