#include <bits/stdc++.h>
using namespace std;

int p[60], aux;
bool mark[60];

typedef void (*function)();

void rot(int a, int b, int c, int d) {
	aux = p[a]; p[a] = p[b]; p[b] = p[c]; p[c] = p[d]; p[d] = aux;
}

void F() {
	rot(1,7,9,3);
	rot(4,8,6,2);
	rot(25,12,39,30);
	rot(26,11,38,29);
	rot(27,10,37,28);
}

void L() {
	rot(10,16,18,12);
	rot(13,17,15,11);
	rot(19,46,37,1);
	rot(22,49,40,4);
	rot(25,52,43,7);
}

void R() {
	rot(28,34,36,30);
	rot(31,35,33,29);
	rot(9,45,54,27);
	rot(6,42,51,24);
	rot(3,39,48,21);
}

void B() {
	rot(54,48,46,52);
	rot(51,47,49,53);
	rot(21,34,43,16);
	rot(20,35,44,17);
	rot(19,36,45,18);
}

void U() {
	rot(19,25,27,21);
	rot(20,22,26,24);
	rot(52,10,3,36);
	rot(53,13,2,33);
	rot(54,16,1,30);
}

void D() {
	rot(37,43,45,39);
	rot(40,44,42,38);
	rot(7,18,48,28);
	rot(8,15,47,31);
	rot(9,12,46,34);
}

char str[100];
void solve() {
	int size = strlen(str);
	bool op;
	function fn;
	for (int i = 0; i < size; i++) {
		op = ((str[i]&0x20) > 0), str[i]&=~0x20;
		if (str[i] == 'F') fn = F;
		else if (str[i] == 'L') fn = L;
		else if (str[i] == 'R') fn = R;
		else if (str[i] == 'B') fn = B;
		else if (str[i] == 'U') fn = U;
		else fn = D;
		fn();
		if (op) fn(), fn();
	}
}

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b%a, a);
}

int lcm(int a, int b) {
	return a*(b/gcd(a,b));
}

int count() {
	for (int i = 1; i <= 54; i++) p[i] = i;
	solve();
	memset(mark,0,sizeof mark);
	int size, k, c = 1;
	for (int i = 1; i <= 54; i++) {
		if (!mark[i]) {
			size = 0, k = i;
			do {
				k = p[k];
				mark[k] = 1;
				size++;
			} while (k != i);
			//printf("> %d\n", size);
			c = lcm(c, size);
		}
	}
	return c;
}

int main() {
	while (scanf("%s", str) == 1) {
		printf("%d\n", count());
	}
}