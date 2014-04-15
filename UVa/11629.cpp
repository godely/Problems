#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long

using namespace std;

map<string, int> mapa;
char str[2000];
int val, v;
bool ok;
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	mapa.clear();
	rp(i,N) {
		scanf("%s %d.%d", str, &val, &v);
		mapa[str]=(val*10)+v;
	}
	rp(i,M) {
		val = 0;
		while (scanf("%s", str)) {
			if (str[0]=='+') continue;
			if (str[0]=='<' || str[0]=='>' || str[0]=='=') {
				scanf("%d", &v);
				v*=10;
				ok = 0;
				if (str[1] == '=') {
					if (str[0] == '<' && val <= v) ok = 1;
					else if (str[0] == '>' && val >= v) ok = 1;
				} else {
					if (str[0] == '<' && val < v) ok = 1;
					else if (str[0] == '>' && val > v) ok = 1;
					else if (str[0] == '=' && val == v) ok = 1;
				}
				if (ok) printf("Guess #%d was correct.\n", i+1);
				else printf("Guess #%d was incorrect.\n", i+1);
				break;
			}
			val += mapa[str];
		}
	}
	return 0;
}