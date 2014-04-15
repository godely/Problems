//by stor
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define LL int
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define score(a,b) ((a==b) ? 2 : -1)

int d[100][100], sizeP, sizeQ;
char P[100], Q[100];
int back[100][100][2];

int main() {
	while (scanf("%s%s", P, Q) == 2) {
		sizeP = strlen(P);
		sizeQ = strlen(Q);
		d[0][0] = 0;
		back[0][0][0] = back[0][0][1] = -1;
		fr(i,1,sizeP) d[i][0] = d[i-1][0] - 1, back[i][0][0] = i-1, back[i][0][1] = 0;
		fr(j,1,sizeQ) d[0][j] = d[0][j-1] - 1, back[0][j][0] = 0, back[0][j][1] = j-1;
		fr(i,1,sizeP+1) {
			fr(j,1,sizeQ+1) {
				if (d[i][j-1] > d[i-1][j]) {
					back[i][j][0] = i;
					back[i][j][1] = j-1;
					d[i][j] = d[i][j-1] - 1;
				} else {
					back[i][j][0] = i-1;
					back[i][j][1] = j;
					d[i][j] = d[i-1][j] - 1;
				}
				if (d[i-1][j-1] + score(P[i-1], Q[i-1]) > d[i][j]) {
					back[i][j][0] = i-1;
					back[i][j][1] = j-1;
					d[i][j] = d[i-1][j-1] + score(P[i-1], Q[i-1]);
				}
				printf("%d ", d[i][j]);
			}
			printf("\n");
		}
		printf("%d\n", d[sizeP][sizeQ]);
		stack<string> l;
		int a = sizeP, b = sizeQ, aux;
		while (a != -1) {
			if (back[a][b][0] == a-1 && back[a][b][1] == b-1) {
				l.push("Replace\n");
			} else if (back[a][b][0] == a-1 && back[a][b][1] == b) {
				l.push("Delete\n");
			} else {
				l.push("Insert\n");
			}
			aux = a;
			a = back[a][b][0];
			b = back[aux][b][1];
		}
		printf("%d\n", l.size());
		while (!l.empty()) {
			printf("%s", l.top().c_str());
			l.pop();
		}
	}
	return 0;
}