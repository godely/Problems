#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <iomanip>
typedef double ld;
typedef long long ll;
#define iter(c) __typeof((c).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define fr(a,b,c) for(int a = b; a < c; ++a)
#define rp(a,c) fr(a,0,c)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oo 0x3F3F3F3F

using namespace std;

int T;
char str[1000];
int cnt;
ld L[110][53];
int M[110];
void rec() {
	int id = cnt++;
	rp(i,51) L[id][i] = 0;
	if (str[id] == 'x') {
		L[id][1] = 1;
		M[id] = 1;
		return;
	}
	int idl = cnt;
	rec();
	int idr = cnt;
	rec();
	if (str[id] == 'M') {
		M[id] = min(50,M[idl]+M[idr]);
		for (int i = 0; i <= M[idl]; i++) {
			for (int j = 0; i+j <= M[id]; j++) {
				L[id][i+j] += L[idl][i]*L[idr][j];
			}
		}
	} else {
		M[id] = min(50,M[idl]+M[idr]);
		for (int i = 0; i <= M[idl]; i++) {
			L[id][i] += L[idl][i];
			for (int j = 0; i+j <= M[id]; j++) {
				L[id][i+j] -= L[idl][i]*L[idr][j];
			}
		}
		for (int i = 0; i <= M[idr]; i++) L[id][i] += L[idr][i];
	}
	return;
}

int main () {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		cnt = 0;
		rec();
		long double r = 1;
		for (ll i = 0; i <= M[0]; i++) {
			r -= L[0][i]/(i+1);
		}
		cout << fixed << setprecision(6) << r << endl;
	}
	return 0;
}