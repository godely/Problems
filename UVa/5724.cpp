#include <bits/stdc++.h>
using namespace std;

struct no {
	int left, right, val;
	no() : left(-1), right(-1), val(-1) {}
	no(int val, int left = -1, int right = -1) : val(val), left(left), right(right) {}
} N[10100];
int k = 0;

void insert(int x, int val) {
	if (val < N[x].val) {
		if (N[x].left == -1) {
			N[x].left = k++;
			N[N[x].left] = no(val);
		} else {
			insert(N[x].left, val);
		}
	} else {
		if (N[x].right == -1) {
			N[x].right = k++;
			N[N[x].right] = no(val);
		} else {
			insert(N[x].right, val);
		}
	}
}

void printPost(int x) {
	if (~N[x].left) printPost(N[x].left);
	if (~N[x].right) printPost(N[x].right);
	printf("%d\n", N[x].val);
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		if (!k) {
			N[k++] = no(n);
		} else {
			insert(0,n);
		}
	}
	printPost(0);
	return 0;
}