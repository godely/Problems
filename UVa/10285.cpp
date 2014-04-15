#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct cell {
	int id;
	bool visited;
	int longestPath;
} cells[110][110];

int R, C;

int F(int i, int j) {
	if (cells[i][j].visited) return cells[i][j].longestPath;

	if (i-1 >= 0) {
		if (cells[i][j].id > cells[i-1][j].id) {
			int longO = F(i-1,j);
			if (cells[i][j].longestPath < 1 + longO) {
				cells[i][j].longestPath = 1 + longO;
			}
		}
	}
	if (j-1 >= 0) {
		if (cells[i][j].id > cells[i][j-1].id) {
			int longO = F(i,j-1);
			if (cells[i][j].longestPath < 1 + longO) {
				cells[i][j].longestPath = 1 + longO;
			}
		}
	}
	if (i+1 < R) {
		if (cells[i][j].id > cells[i+1][j].id) {
			int longO = F(i+1,j);
			if (cells[i][j].longestPath < 1 + longO) {
				cells[i][j].longestPath = 1 + longO;
			}
		}
	}
	if (j+1 < C) {
		if (cells[i][j].id > cells[i][j+1].id) {
			int longO = F(i,j+1);
			if (cells[i][j].longestPath < 1 + longO) {
				cells[i][j].longestPath = 1 + longO;
			}
		}
	}
	cells[i][j].visited = true;
	return cells[i][j].longestPath;
}

void process() {
	string nome;
	cin >> nome >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> cells[i][j].id;
			cells[i][j].visited = false;
			cells[i][j].longestPath = 1;
		}
	}

	int max = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!cells[i][j].visited) {
				int path = F(i,j);
				if (path > max)
					max = path;
			}
		}
	}

	cout << nome << ": " << max << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		process();
	}
	return 0;
}
