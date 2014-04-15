#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

double mapa[130];
char str[500];
int main() {
	mapa['W'] = 1.0;
	mapa['H'] = 1/2.0;
	mapa['Q'] = 1/4.0;
	mapa['E'] = 1/8.0;
	mapa['S'] = 1/16.0;
	mapa['T'] = 1/32.0;
	mapa['X'] = 1/64.0;
	double cnt;
	int l, size;
	while (scanf("%s", str) == 1) {
		if (str[0] == '*') break;
		size = strlen(str);
		l = 0;
		cnt = 0;
		for (int i = 0; i < size; i++) {
			if (str[i] == '/') {
				if (cnt == 1) l++;
				cnt = 0;
				continue;
			}
			cnt += mapa[str[i]];
		}
		printf("%d\n", l);
	}
	return 0;
}