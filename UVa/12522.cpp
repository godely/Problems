//by stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

//I = 1,  V = 5,  X = 10,  L = 50,  C = 100,  D = 500,  M = 1000
/*4: IIII -> IV
  9: VIIII -> IX
  40: XXXX -> XL
  90: LXXXX -> XC
  400: CCCC -> CD
  900: DCCCC -> CM
*/

char P[500], T[500];
int size, tSize;

int main() {
	while (scanf("%s", P) == 1 && P[0] != '*') {
		size = strlen(P);
		tSize = 0;
		rp(i,size) {
			if (i+4 < size) {
				if (P[i] == 'D' && P[i+1] == 'C' && P[i+2] == 'C' && P[i+3] == 'C' && P[i+4] == 'C') { T[tSize++] = 'C'; T[tSize++] = 'M'; i += 4; continue; }
				else if (P[i] == 'L' && P[i+1] == 'X' && P[i+2] == 'X' && P[i+3] == 'X' && P[i+4] == 'X') { T[tSize++] = 'X'; T[tSize++] = 'C'; i += 4; continue; }
				else if (P[i] == 'V' && P[i+1] == 'I' && P[i+2] == 'I' && P[i+3] == 'I' && P[i+4] == 'I') { T[tSize++] = 'I'; T[tSize++] = 'X'; i += 4; continue; }
			}
			if (i+3 < size) {
				if (P[i] == 'C' && P[i+1] == 'C' && P[i+2] == 'C' && P[i+3] == 'C') { T[tSize++] = 'C'; T[tSize++] = 'D'; i += 3; continue; }
				else if (P[i] == 'X' && P[i+1] == 'X' && P[i+2] == 'X' && P[i+3] == 'X') { T[tSize++] = 'X'; T[tSize++] = 'L'; i += 3; continue; }
				else if (P[i] == 'I' && P[i+1] == 'I' && P[i+2] == 'I' && P[i+3] == 'I') { T[tSize++] = 'I'; T[tSize++] = 'V'; i += 3; continue; }
			}
			T[tSize++] = P[i];
		}
		T[tSize] = '\0';
		
		int lim = size - tSize, e = inf, c = inf, tempE, tempC;
		for (int i = 0; i <= lim; i++) {
			tempE = lim, tempC = 0;
			for (int j = 0; j < tSize; j++) {
				if (P[i+j] != T[j]) tempE++, tempC++;
			}
			if ((tempE+tempC < e+c) || (tempE+tempC == e+c && tempE < e)) e = tempE, c = tempC; 
		}
		printf("%d %d\n", e, c);
	}
	return 0;
}