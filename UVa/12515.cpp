//by stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

struct binario {
	long long b[2];
	int size;
	int rightCount[111], leftCount[111];
	
	binario() {}
	binario(char *p) {
		b[0] = b[1] = 0;
		size = strlen(p);
		int type = 0;
		for (int j = size-1, i = 0; j >= 0; j--, i++) {
			if (i == 64) i = 0, type = 1;
			b[type] |= (long long)(p[j]-'0')<<i;
		}
		
		rightCount[0] = 0; leftCount[size-1] = 0;
		for (int i = 1; i < size; i++) {
			rightCount[i] = rightCount[i-1] + (p[size-i]=='1');
		}
		for (int i = size-2; i >= 0; i--) {
			leftCount[i] = leftCount[i+1] + (p[size-i-2]=='1');
		}
	}

	binario shiftLeft() {
		binario ret = binario();
		ret.b[1] = b[1]<<1;
		if (b[0]&(1LL<<63)) ret.b[1] |= 1;
		ret.b[0] = b[0]<<1;
		ret.size = size+1;
		return ret;
	}
	
	int operator^(const binario &lhs) const {
		return __builtin_popcountll(b[0]^lhs.b[0]) + __builtin_popcountll(b[1]^lhs.b[1]);
	}
} bin[1100], T;

char P[200];
int main() {
	int M, Q, ans, temp, res;
	scanf("%d%d", &M, &Q);
	rp(i,M) {
		scanf("%s", P);
		bin[i] = binario(P);
	}
	binario aux, ori;
	rp(i,Q) {
		scanf("%s", P);
		ori = binario(P);
		ans = 0x3f3f3f3f, res = 1;
		rp(j,M) {
			aux = ori;
			for (int k = 0; aux.size <= bin[j].size; k++, aux = aux.shiftLeft()) {
				temp = (bin[j]^aux) - bin[j].rightCount[k] - bin[j].leftCount[aux.size-1];
				if (temp < ans) ans = temp, res = j+1;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}