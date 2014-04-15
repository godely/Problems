#include <bits/stdc++.h>
using namespace std;
#define MAXM 21111
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair

int N;
queue<pair<int,int> > fila;
char grid[111][111];
int hori_i[MAXM], hori_j[MAXM], hori_s[MAXM], hori_left[MAXM], hori_id[111][111], horiSize;
int vert_i[MAXM], vert_j[MAXM], vert_s[MAXM], vert_left[MAXM], vert_id[111][111], vertSize;
char str[1111];

void solveHori(int k) {
	int _i = hori_i[k], _j = hori_j[k], _s = hori_s[k];
	for (int j = _j; j < N && grid[_i][j] != '#'; j++) {
		if (grid[_i][j] == '.') {
			grid[_i][j] = _s+'0';
			hori_left[k]--;
			if (vert_id[_i][j]) {
				vert_left[vert_id[_i][j]]--;
				vert_s[vert_id[_i][j]] -= _s;
				if (vert_left[vert_id[_i][j]] == 1) fila.push(mp(vert_id[_i][j],1));
			}
		}
	}
}

void solveVert(int k) {
	int _i = vert_i[k], _j = vert_j[k], _s = vert_s[k];
	for (int i = _i; i < N && grid[i][_j] != '#'; i++) {
		if (grid[i][_j] == '.') {
			grid[i][_j] = _s+'0';
			vert_left[k]--;
			if (hori_id[i][_j]) {
				hori_left[hori_id[i][_j]]--;
				hori_s[hori_id[i][_j]] -= _s;
				if (hori_left[hori_id[i][_j]] == 1) fila.push(mp(hori_id[i][_j],0));
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	while (N > 0) {
		while (!fila.empty()) fila.pop();
		memset(hori_id,0,sizeof hori_id);
		memset(vert_id,0,sizeof vert_id);
		rp(i,N) {
			scanf("%s", grid[i]);
		}
		scanf("%*s\n");
		horiSize = 1;
		while (gets(str) && str[0] != 'D') {
			int _i, _j, _s;
			sscanf(str, "%d %d %d", &_j, &_i, &_s); _i--, _j--;
			
			hori_left[horiSize] = 0;
			for (int j = _j; j < N && grid[_i][j] != '#'; j++) {
				hori_id[_i][j] = horiSize;
				if (grid[_i][j] != '.') {
					_s -= (grid[_i][j] - '0');
				} else hori_left[horiSize]++;
			}
			if (hori_left[horiSize] == 1) fila.push(mp(horiSize, 0));
			hori_i[horiSize] = _i;
			hori_j[horiSize] = _j;
			hori_s[horiSize] = _s;
			horiSize++;
		}
		vertSize = 1;
		while (gets(str) && strlen(str) > 3) {
			int _i, _j, _s;
			sscanf(str, "%d %d %d", &_j, &_i, &_s); _i--, _j--;
			
			vert_left[vertSize] = 0;
			for (int i = _i; i < N && grid[i][_j] != '#'; i++) {
				vert_id[i][_j] = vertSize;
				if (grid[i][_j] != '.') {
					_s -= (grid[i][_j] - '0');
				} else vert_left[vertSize]++;
			}
			if (vert_left[vertSize] == 1) fila.push(mp(vertSize, 1));
			vert_i[vertSize] = _i;
			vert_j[vertSize] = _j;
			vert_s[vertSize] = _s;
			vertSize++;
		}
		
		while (!fila.empty()) {
			pair<int,int> aux = fila.front();
			fila.pop();
			if (aux.second == 0) {
				solveHori(aux.first);
			} else {
				solveVert(aux.first);
			}
		}
		
		rp(i,N) printf("%s\n", grid[i]);
		printf("\n");
		
		N = atoi(str);
	}
}