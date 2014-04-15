#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int N, M, t;
char str[1000];
string P[300];
int G[1000][1000];

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

bool pode(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }
void dfs(int i, int j, int c) {
	G[i][j] = c;
	rp(k,4) if (pode(i+di[k],j+dj[k]) && G[i+di[k]][j+dj[k]] == 1) dfs(i+di[k],j+dj[k],c);
}

int dfs2(int i, int j) {
	if (G[i][j] != 0) return G[i][j];
	G[i][j] = 1;
	int col = -1;
	rp(k,4) {
		if (pode(i+di[k],j+dj[k])) {
			int ret = dfs2(i+di[k],j+dj[k]);
			if (ret == -1) return G[i][j] = -1;
			else if (ret > 1) {
				if (col == -1) col = ret;
				else if (col != ret) return G[i][j] = -1;
			}
		} else return G[i][j] = -1;
	}
	if (col == -1) col = 1;
	return G[i][j] = col;
}

int B[41000];
char R[10];
char RES[41000];
int main() {
	int cas = 1;
	P['0'] = "0000";
	P['1'] = "0001";
	P['2'] = "0010";
	P['3'] = "0011";
	P['4'] = "0100";
	P['5'] = "0101";
	P['6'] = "0110";
	P['7'] = "0111";
	P['8'] = "1000";
	P['9'] = "1001";
	P['a'] = "1010";
	P['b'] = "1011";
	P['c'] = "1100";
	P['d'] = "1101";
	P['e'] = "1110";
	P['f'] = "1111";
	R[0] = 'W';
	R[1] = 'A';
	R[2] = 'K';
	R[3] = 'J';
	R[4] = 'S';
	R[5] = 'D';
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		memset(B,0,sizeof B);
		rp(i,N) {
			t = 0;
			scanf("%s", str);
			rp(j,M) {
				rp(k,4) G[i][t++] = P[str[j]][k]-'0';
			}
		}
		M = t;
		int c = 2;
		rp(i,N) rp(j,M) if (G[i][j] == 1) dfs(i,j,c++);
		rp(i,N) rp(j,M) if (G[i][j] == 0) {
			int ret = dfs2(i,j);
			if (ret != -1) B[ret-2]++;
		}
		c-=2;
		sort(B,B+c);
		printf("Case %d: ", cas++);
		rp(i,c) RES[i] = R[B[i]];
		sort(RES,RES+c);
		rp(i,c) printf("%c", RES[i]);
		printf("\n");
	}
	return 0;
}