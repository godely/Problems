#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define _INPUT -1
#define _AND 0
#define _NOT 1
#define _OR 2
#define _XOR 3

#define NO_ERROR 0
#define INVERT 1
#define ALWAYS_1 2
#define ALWAYS_0 3

int tp(char a) {
	if (a == 'a') return _AND;
	else if (a == 'n') return _NOT;
	else if (a == 'o') return _OR;
	else return _XOR;
}

struct gate {
	int type, i1, i2;
	gate(int type = -1, int i1 = -1, int i2 = -1):type(type),i1(i1),i2(i2) {}
} g[100];
int val[100], mark[100], passo = 0;

bool op(int value, int erro) {
	if (erro == NO_ERROR) return value;
	else if (erro == INVERT) return 1-value;
	else if (erro == ALWAYS_1) return 1;
	else return 0;
}

bool solve(int ind, int erro = 0) {
	if (g[ind].type == _INPUT || mark[ind] == passo) return val[ind];
	mark[ind] = passo;
	int value;
	if (g[ind].type == _AND) value = (solve(g[ind].i1)&solve(g[ind].i2));
	else if (g[ind].type == _OR) value = (solve(g[ind].i1)|solve(g[ind].i2));
	else if (g[ind].type == _XOR) value = (solve(g[ind].i1)^solve(g[ind].i2));
	else value = 1 - solve(g[ind].i1);
	return val[ind] = op(value,erro);
}

int I, G, O;
int q, BI[1000][21], BO[1000][21], Out[50];
char type[10], a[10], b[10];
int main() {
	int cas = 1;
	while (scanf("%d%d%d", &I, &G, &O) == 3 && (I+G+O)>0) {
		rp(i,G+I+O) g[i] = gate();
		rp(i,G) {
			scanf("%s%s", type, a);
			if (type[0] != 'n') {
				scanf("%s", b);
				g[i] = gate(tp(type[0]), (a[0]=='i' ? G : 0) + atoi(a+1) - 1, (b[0]=='i' ? G : 0) + atoi(b+1) - 1);
			} else {
				g[i] = gate(tp(type[0]), (a[0]=='i' ? G : 0) + atoi(a+1) - 1);
			}
		}
		rp(i,O) scanf("%d", &Out[i]), Out[i]--;

		scanf("%d", &q);
		rp(i,q) {
			rp(j,I) scanf("%d", &BI[i][j]);
			rp(j,O) scanf("%d", &BO[i][j]);
		}
		
		printf("Case %d: ", cas++);
		bool ok = 1;
		rp(i,q) {
			rp(j,I) val[G+j] = BI[i][j];
			passo++;
			rp(j,G) if(mark[j] != passo) solve(j);
			rp(j,O) if(val[Out[j]] != BO[i][j]) {
				ok = 0;
				i = q;
				break;
			}
		}
		
		if (ok) printf("No faults detected\n");
		else {
			int errorWhere = -1, errorType = -1;
			rp(i,G) {
				rp(p,3) {
					ok = 1;
					rp(j,q) {
						rp(k,I) val[G+k] = BI[j][k];
						passo++;
						solve(i,p+1);
						rp(k,G) if(mark[k] != passo) solve(k);
						rp(k,O) if(val[Out[k]] != BO[j][k]) {
							ok = 0;
							j = q;
							break;
						}
					}
					if (ok) {
						if (errorWhere == -1) errorWhere = i+1, errorType = p+1;
						else {
							printf("Unable to totally classify the failure\n");
							goto fim;
						}
					}
				}
			}
			printf("Gate %d is failing; output ", errorWhere);
			if (errorType == 1) printf("inverted\n");
			else if (errorType == 2) printf("stuck at 1\n");
			else printf("stuck at 0\n");
		}
		fim:;
	}
	return 0;
}