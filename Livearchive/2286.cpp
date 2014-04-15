#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int get(char c) {
	if (c >= '0' && c <= '9') return c-'0';
	return 10+c-'A';
}

char get2(int n) {
	if (n < 10) return n+'0';
	else return n-10+'A';
}

char in[300];
int mem[300];

int main() {
	while (scanf("%s", in) == 1 && in[0] != '8') {
		int size = strlen(in);
		while (size < 256) scanf("%s", in+size), size = strlen(in);
		rp(i,256) mem[i] = get(in[i]);
		int pt = 0, S;
		int A = 0, B = 0;
		while (1) {
				switch(mem[pt]) {
					case 0:
						A = mem[(mem[pt+1]<<4) + mem[pt+2]];
						pt+=3;
						break;
					case 1:
						mem[(mem[pt+1]<<4) + mem[pt+2]] = A;
						pt+=3;
						break;
					case 2:
						swap(A,B);
						pt++;
						break;
					case 3:
						S = A+B;
						A = S&15;
						B = S>>4;
						pt++;
						break;
					case 4:
						A = (A+1)&15;
						pt++;
						break;
					case 5:
						A = (A-1)&15;
						pt++;
						break;
					case 6:
						if (!A) pt = (mem[pt+1]<<4) + mem[pt+2];
						else pt+=3;
						break;
					case 7:
						pt = (mem[pt+1]<<4) + mem[pt+2];
						break;
					case 8:
						goto fim;
						break;
			}
		}
		fim:;
		rp(i,256) printf("%c", get2(mem[i]));
		printf("\n");
	}
	return 0;
}