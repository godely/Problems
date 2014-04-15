#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int btRow[10];
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

void prt(int cas, int num) {
	if (cas < 10)
		printf(" %d     ", cas);
	else
		printf("%d     ", cas);
	for (int j = 1; j <= 8; j++) {
		printf(" %d", res[num][j]);
	}
	printf("\n");
}

int main() {
	backtrack(1);
	int T, row, col, cas;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &row, &col);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		cas = 1;
		for (int i = 0; i < size; i++) {
			if (res[i][col] == row) {
				prt(cas++, i);
			}
		}
		if (T) printf("\n");
	}
}
