#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a<c; a++)
#define rp(a,b) fr(a,0,b)

int ARV[1<<22][3], LAZY[1<<22];

void build(int R, int i, int j) {
	if (i == j) ARV[R][0] = 1, ARV[R][1] = ARV[R][2] = 0, LAZY[R] = 0;
	else {
		LAZY[R] = 0;
		build(2*R, i, (i+j)/2);
		build(2*R+1, (i+j)/2+1, j);
		rp(k,3) ARV[R][k] = ARV[2*R][k] + ARV[2*R+1][k];
	}
}

void fix(int R, bool isLeaf) {
	if (!LAZY[R]) return;
	int aux;
	rp(i,LAZY[R]) aux = ARV[R][0], ARV[R][0] = ARV[R][2], ARV[R][2] = ARV[R][1], ARV[R][1] = aux;
	if (!isLeaf) LAZY[2*R] = (LAZY[2*R]+LAZY[R])%3, LAZY[2*R+1] = (LAZY[2*R+1]+LAZY[R])%3;
	LAZY[R] = 0;
}

void update(int R, int i, int j, int a, int b) {
	fix(R, i==j);
	if (i > b || j < a) return;
	if (i >= a && j <= b) {
		LAZY[R]=(LAZY[R]+1)%3;
		fix(R, i==j);
	} else {
		update(2*R, i, (i+j)/2, a, b);
		update(2*R+1, (i+j)/2+1, j, a, b);
		rp(k,3) ARV[R][k] = ARV[2*R][k] + ARV[2*R+1][k];
	}
}

struct ret {
	int a, b, c;
	ret(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

ret query(int R, int i, int j, int a, int b) {
	if (i > b || j < a) return ret(0,0,0);
	fix(R, i==j);
	if (i >= a && j <= b) {
		return ret(ARV[R][0],ARV[R][1],ARV[R][2]);
	} else {
		ret r1 = query(2*R, i, (i+j)/2, a, b);
		ret r2 = query(2*R+1, (i+j)/2+1, j, a, b);
		r1.a += r2.a; r1.b += r2.b; r1.c += r2.c;
		return r1;
	}
}

char str[10];
int a, b;
ret aux;
int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) == 2) {
		build(1,1,N);
		rp(i,M) {
			scanf("%s%d%d", str, &a, &b);
			if (str[0] == 'C') {
				aux = query(1,1,N,a,b);
				printf("%d %d %d\n", aux.a, aux.b, aux.c);
			} else {
				update(1,1,N,a,b);
			}
		}
		printf("\n");
	}
}