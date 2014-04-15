#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for (int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define maxn 200000
#define maxm 21000
#define F first
#define S second
typedef pair<int,int> ii;

char T[maxn], P[maxn];
int n, m;
int SA[maxn], tempSA[maxn];
int RA[maxn], tempRA[maxn];
int PL[maxn];
int c[maxn];

void csort(int k) {
	memset(c,0,sizeof c);
	int maxi = max(n,300);
	for (int i = 0; i < n; i++) c[i+k < n ? RA[i+k] : 0]++;
	for (int i = 0, sum = 0, t; i < maxi; i++) t = c[i], c[i] = sum, sum+=t;
	for (int i = 0; i < n; i++) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for (int i = 0; i < n; i++) SA[i] = tempSA[i];
}

void constructSA() {
	memset(RA,0,sizeof RA);
	for (int i = 0; i < n; i++) SA[i] = i, RA[i] = T[i];
	for (int k = 1; k < n; k<<=1) {
		csort(k); csort(0);
		int keep = 0, r = 0;
		tempRA[SA[0]] = r;
		for (int i = 1; i < n; i++) {
			if (RA[SA[i-1]] == RA[SA[i]] && RA[SA[i-1]+k] == RA[SA[i]+k]) tempRA[SA[i]] = r, keep = 1;
			else tempRA[SA[i]] = ++r;
		}
		for (int i = 0; i < n; i++) RA[i] = tempRA[i];
		if (!keep) break;
	}
}

struct st {
	string s;
	int ind;
	st() {}
	bool operator <(const st &lhs)const{
		int s1=s.size(), s2=lhs.s.size();
		if(s1!=s2) return s1<s2;
		int cm = s.compare(lhs.s);
		if(cm) return cm<0;
		return ind<lhs.ind;
	}
} ns[maxm];

typedef set<int>::iterator s_it;
void merge(set<int> &a, set<int> &b, set<int> &ret) {
	s_it it1 = a.begin(), it2 = b.begin();
	for (; ret.size() < 10;) {
		if (it1 != a.end() && it2 != b.end()) {
			if ((*it1) < (*it2)) ret.insert((*it1)), it1++;
			else ret.insert((*it2)), it2++;
		} else if (it1 != a.end()) ret.insert((*it1)), it1++;
		else if (it2 != b.end()) ret.insert((*it2)), it2++;
		else break;
	}
}

void print(set<int> &s) {
	int foi = 0;
	for (s_it it = s.begin(); it != s.end(); it++) {
		if (foi) printf(" ");
		else foi = 1;
		printf("%d", ns[(*it)].ind);
	}
	printf("\n");
}

set<int> ST[50*maxn];
void buildST(int R, int i, int j) {
	ST[R] = set<int>();
	if (i == j) ST[R].insert(PL[SA[i]]);
	else {
		buildST(2*R, i, (i+j)/2);
		buildST(2*R+1, (i+j)/2+1, j);
		merge(ST[2*R], ST[2*R+1], ST[R]);
	}
	//printf("(%d %d %d):\n", R, i, j);
	//print(ST[R]);
}

set<int> query(int R, int i, int j, int l, int r) {
	if (j < l || i > r) return set<int>();
	else if (i >= l && j <= r) return ST[R];
	else {
		set<int> ret = set<int>();
		set<int> a = query(2*R, i, (i+j)/2, l, r);
		set<int> b = query(2*R+1, (i+j)/2+1, j, l, r);
		merge(a, b, ret);
		return ret;
	}
}

ii stringMatching() {
	int lo = 0, hi = n-1, mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res >= 0) hi = mid;
		else lo = mid + 1;
	}
	if (strncmp(T + SA[lo], P, m) != 0) return ii(-1, -1);
	ii ans; ans.first = lo;

	lo = 0; hi = n - 1; mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res > 0) hi = mid;
		else lo = mid + 1;
	}
	if (strncmp(T + SA[hi], P, m) != 0) hi--;
	ans.second = hi;
	return ans;
} 

set<int> aux;
int main() {
	int k; scanf("%d", &k);
	n = 0;
	Fr(i,0,k) {
		cin >> ns[i].s;
		ns[i].ind = i+1;
	}
	sort(ns,ns+k);
	Fr(i,0,k) {
		int size = ns[i].s.size();
		Fr(j,0,size) T[n] = ns[i].s[j], PL[n++] = i;
		T[n] = '$', PL[n++] = -1;
	}
	T[n] = '\0';
	constructSA();
	buildST(1,k,n-1);
	//Fr(i,0,n) printf("%3d %3d %3d %s\n", i, SA[i], PL[SA[i]], T+SA[i]);
	int Q; scanf("%d", &Q);
	Fr(i,0,Q) {
		scanf("%s", P);
		m = strlen(P);
		ii ret = stringMatching();
		if (ret.F == -1) printf("-1\n");
		else {
			aux = query(1,k,n-1,ret.F,ret.S);
			print(aux);
		}
	}
	return 0;
}