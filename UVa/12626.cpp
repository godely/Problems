#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char P[1000];
int alf[30];
int main() {
	int t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", P);
		memset(alf,0,sizeof alf);
		for (int i = 0; P[i]; i++) alf[P[i]-'A']++;
		printf("%d\n",min(alf['M'-'A'], min(alf['A'-'A']/3, min(alf['R'-'A']/2, min(alf['G'-'A'], min(alf['I'-'A'], alf['T'-'A']))))));
	}
	return 0;
}