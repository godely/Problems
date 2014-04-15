#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char in[70];
int num[70], tmp[70], size;

bool comp() {
	rp(i,size) if (num[i] != tmp[i]) return false;
	return true;
}

void shift() {
	int q = tmp[0];
	rp(i,size-1) tmp[i] = tmp[i+1];
	tmp[size-1] = q;
}

bool mult(int x) {
	int cry = 0;
	rp(i,size) tmp[i] = num[i];
	rp(i,size) {
		tmp[i] *= x;
		tmp[i] += cry;
		cry = tmp[i]/10;
		tmp[i] %= 10;
	}
	if (cry) return false;
	rp(i,size) {
		if (comp()) return true;
		shift();
	}
	return false;
}

int main() {
	while (scanf("%s", in) == 1) {
		size = strlen(in);
		rp(i,size) num[size-1-i] = in[i]-'0';
		fr(i,2,min(size+1,10)) {
			if (!mult(i)) goto nops;
		}
		printf("%s is cyclic\n", in);
		continue;
		nops:;
		printf("%s is not cyclic\n", in);
	}
	return 0;
}