#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int fCTP(int n) {
	if (n <= 100) return n*2;
	else if (n <= 10000) return 200 + (n-100)*3;
	else if (n <= 1000000) return 29900 + (n-10000)*5;
	else return 4979900 + (n-1000000)*7;
}

int fPTC(int n) {
	if (n <= 200) return n/2;
	else if (n <= 29900) return 100 + (n-200)/3;
	else if (n <= 4979900) return 10000 + (n-29900)/5;
	else return 1000000 + (n-4979900)/7;
}

int main() {
	int A, B, C;
	while (scanf("%d%d", &A, &B) == 2 && A > 0) {
		C = fPTC(A);
		int ini = 0, fim = (C+1)/2, meio;
		while (ini != fim) {
			meio = (ini+fim)/2;
			if (fCTP(C-meio)-fCTP(meio) > B) ini = meio+1;
			else fim = meio;
		}
		printf("%d\n", fCTP(ini));
	}
	return 0;
}