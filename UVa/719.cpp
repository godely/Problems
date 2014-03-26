#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100

char T[MAXN];
int n;
int RA[MAXN], SA[MAXN], tempRA[MAXN], tempSA[MAXN], c[MAXN];

//gatagaca


void csort(int k) {
	int r = max(n,300);
	rp(i,r) c[i] = 0;
	rp(i,n-k) c[RA[i+k]]++;
	c[0]+=k;
	int sum = 0, t;
	rp(i,r) {
		t = c[i];
		c[i] = sum;
		sum += t;
	}
	rp(i,n) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	rp(i,n) SA[i] = tempSA[i];
}

void suffixArray() {
	rp(i,n) {
		SA[i] = i;
		RA[i] = T[i];
	}
	for(int k = 1; k < n; k<<=1) {
		csort(k);
		csort(0);
		tempRA[SA[0]] = 0;
		int r = 0;
		fr(i,1,n) {
			if (RA[SA[i]] != RA[SA[i-1]] || ((SA[i]+k < n) ? RA[SA[i]+k] : -1) != ((SA[i-1]+k < n) ? RA[SA[i-1]+k] : -1)) r++;
			tempRA[SA[i]] = r;
		}
		rp(i,n) RA[i] = tempRA[i];
	}
}

int main() {
	int numCas; scanf("%d", &numCas);
	while (numCas--) {
		scanf("%s", T);
		n = strlen(T);
		suffixArray();
	}
}
