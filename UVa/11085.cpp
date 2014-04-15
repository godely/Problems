#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int btRow[10], in[10];
int res[100][10], size = 0;

bool canPut(int row, int col) {
	for (int j = 1; j < col; j++)
		if (btRow[j] == row || col-j == abs(row-btRow[j])) return false;
	return true;
}

void backtrack(int col) {
	if (col > 8) {
		for (int j = 1; j <= 8; j++) {
			res[size][j] = btRow[j];
		}
		size++;
		return;
	}
	for (int row = 1; row <= 8; row++) {
		if (canPut(row, col)) {
			btRow[col] = row;
			backtrack(col+1);
		}
	}
}

int main() {
	backtrack(1);
	int temp, ans, cas = 1;
	while (scanf("%d", &in[1]) == 1) {
		fr(i,2,9) scanf("%d", &in[i]);
		ans = 100000;
		rp(i,size) {
			temp = 0;
			fr(j,1,9) if (res[i][j] != in[j]) temp++;
			ans = min(ans, temp);
		}
		printf("Case %d: %d\n", cas++, ans);
	}
}
