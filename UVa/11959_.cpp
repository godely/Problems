#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int d1[6], d2[6], temp;
void rot(int a, int b, int c, int d) { temp = d1[a]; d1[a] = d1[b]; d1[b] = d1[c]; d1[c] = d1[d]; d1[d] = temp; }
void LEFT() { rot(2,3,4,5); }
void UP() { rot(0,4,1,2); }
void UL() { rot(0,3,1,5); }

int main() {
	int T;
	scanf("%d", &T);
	bool ok;
	while (T--) {
		rp(i,6) scanf("%1d", &d1[i]);
		rp(i,6) scanf("%1d", &d2[i]);
		rp(i,6) {
			rp(j,4) {
				ok = 1;
				rp(k,6) {
					if (d1[k] != d2[k]) {
						ok = 0;
						break;
					}
				}
				if (ok) {
					printf("Equal\n");
					goto lol;
				}
				LEFT();
			}
			if (i == 0 || i == 4) UP();
			else UL();
		}
		printf("Not Equal\n");
		lol:;
	}
	return 0;
}