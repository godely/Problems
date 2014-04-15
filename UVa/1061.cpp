#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int S[7][2] = {{-1,-1}, {-1,-1}, {4,10}, {9,15}, {-1,-1}, {25,-1}, {6,-1}};
string RES[10000];
int r;
int M[300];
string N[30], Q[10];
int P[30];
string a, b, c;
int main() {
	int cas = 1;
	Q[2] = "A";
	Q[3] = "B";
	Q[5] = "O";
	Q[6] = "AB";
	M['A'] = 2;
	M['B'] = 3;
	M['O'] = 5;
	N[4] = "A";
	N[6] = "AB";
	N[10] = "A";
	N[9] = "B";
	N[15] = "B";
	N[25] = "O";
	P[4] = 2;
	P[6] = 6;
	P[10] = 2;
	P[9] = 3;
	P[15] = 3;
	P[25] = 5;
	while ((cin >> a >> b >> c) && a[0] != 'E') {
		cout << "Case " << (cas++) << ": ";
		if (a[0] == '?' || b[0] == '?') {
			bool sss = 0;
			if (a[0] == '?') sss = 1, swap(a,b);
			
			int i;
			int sa = 1;
			for (i = 0; a[i] != '+' && a[i] != '-'; i++) {
				sa *= M[a[i]];
			}
			
			bool exc = (a[i] == '-');
			
			int sf = 1;
			for (i = 0; c[i] != '+' && c[i] != '-'; i++) {
				sf *= M[c[i]];
			}
			
			exc = exc&(c[i] == '+');
			
			r = 0;
			for (int i = 0; i < 2 && S[sa][i] != -1; i++) {
				if ((S[sa][i]%2) == 0) {
					if (P[4] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%2 == 0 || S[j][1]%2 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
					if (P[6] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%3 == 0 || S[j][1]%3 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
					if (P[10] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%5 == 0 || S[j][1]%5 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
				}
				if ((S[sa][i]%3) == 0) {
					if (P[6] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%2 == 0 || S[j][1]%2 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
					if (P[9] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%3 == 0 || S[j][1]%3 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
					if (P[15] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%5 == 0 || S[j][1]%5 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
				}
				if ((S[sa][i]%5) == 0) {
					if (P[10] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%2 == 0 || S[j][1]%2 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
					if (P[15] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%3 == 0 || S[j][1]%3 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
					if (P[25] == sf) {
						for (int j = 2; j < 7; j++) if (j != 4) {
							if (S[j][0]%5 == 0 || S[j][1]%5 == 0) {
								RES[r++] = Q[j];
							}
						}
					}
				}
			}
			if (!sss) cout << a << " ";
			sort(RES,RES+r);
			r = unique(RES,RES+r)-RES;
			if (r == 0) cout << "IMPOSSIBLE ";
			else if (r == 1 && exc) cout << RES[0] << "+ ";
			else {
				cout << "{" << RES[0] << "+";
				if (!exc) cout << ", " << RES[0] << "-";
				fr(i,1,r) {
					cout << ", " << RES[i] << "+";
					if (!exc) cout << ", " << RES[i] << "-";
				}
				cout << "} ";
			}
			if (sss) cout << a << " " << c << endl;
			else cout << c << endl;
		} else {
			cout << a << " " << b << " ";
			int i;
			int sa = 1;
			for (i = 0; a[i] != '+' && a[i] != '-'; i++) {
				sa *= M[a[i]];
			}
			bool exc = (a[i] == '+');
			
			int sb = 1;
			for (i = 0; b[i] != '+' && b[i] != '-'; i++) {
				sb *= M[b[i]];
			}
			exc = exc|(b[i] == '+');
			
			r = 0;
			for (int i = 0; i < 2 && S[sa][i] != -1; i++) {
				for (int j = 0; j < 2 && S[sb][j] != -1; j++) {
					if (S[sa][i]%2 == 0) {
						if (S[sb][j]%2 == 0) RES[r++] = N[4];
						if (S[sb][j]%3 == 0) RES[r++] = N[6];
						if (S[sb][j]%5 == 0) RES[r++] = N[10];
					}
					if (S[sa][i]%3 == 0) {
						if (S[sb][j]%2 == 0) RES[r++] = N[6];
						if (S[sb][j]%3 == 0) RES[r++] = N[9];
						if (S[sb][j]%5 == 0) RES[r++] = N[15];
					}
					if (S[sa][i]%5 == 0) {
						if (S[sb][j]%2 == 0) RES[r++] = N[10];
						if (S[sb][j]%3 == 0) RES[r++] = N[15];
						if (S[sb][j]%5 == 0) RES[r++] = N[25];
					}
				}
			}
			sort(RES,RES+r);
			r = unique(RES,RES+r)-RES;
			if (r == 0) cout << "IMPOSSIBLE" << endl;
			else if (r == 1 && !exc) cout << RES[0] << "-" << endl;
			else {
				cout << "{" << RES[0] << "-";
				if (exc) cout << ", " << RES[0] << "+";
				fr(i,1,r) {
					cout << ", " << RES[i] << "-";
					if (exc) cout << ", " << RES[i] << "+";
				}
				cout << "}" << endl;
			}
		}
	}
	return 0;
}