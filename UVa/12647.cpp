#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXX 1100000

struct seg {
	int xi, yi, xf, yf;
	seg() {}
	
	bool equal() {
		return yi == yf;
	}
	
	bool operator<(const seg &q) const {
		if (min(yi,yf) != min(q.yi,q.yf)) return min(yi,yf) > min(q.yi,q.yf);
		return max(yi,yf) > max(q.yi,q.yf);
	}
} s[111111];

int seg[2048576<<1];
bool lazy[2048576<<1];
int N, C;
int myx[110000], rep[110000];

int findSet(int i) {
	if (i == -1) return -1;
	else if (i == rep[i]) return i;
	else return rep[i] = findSet(rep[i]);
}
void unionSet(int i, int j) {
	rep[i] = findSet(j);
}

void fix(int R) {
	if (!lazy[R]) return;
	seg[R<<1] = seg[(R<<1)+1] = seg[R];
	lazy[R<<1] = lazy[(R<<1)+1] = 1;
	lazy[R] = 0;
}

void update(int R, int i, int j, int a, int b, int id) {
	if (i != j) fix(R);
	else lazy[R] = 0;
	if (j < a || i > b) return;
	else if (i >= a && j <= b) {
		seg[R] = id;
		lazy[R] = 1;
	} else {
		int m = (i+j)>>1;
		update(R<<1,i,m,a,b,id);
		update((R<<1)+1,m+1,j,a,b,id);
	}
}

int query(int R, int i, int j, int a) {
	if (i != j) fix(R);
	else lazy[R] = 0;
	if (i == j) return seg[R];
	else {
		int m = (i+j)>>1;
		if (a <= m) return query(R<<1,i,m,a);
		else return query((R<<1)+1,m+1,j,a);
	}
}

int main() {
	while (scanf("%d%d", &N, &C) == 2) {
		rp(i,N) {
			scanf("%d%d%d%d", &s[i].xi, &s[i].yi, &s[i].xf, &s[i].yf);
			s[i].xi++, s[i].yi++, s[i].xf++, s[i].yf++;
			if (s[i].xi > s[i].xf) {
				swap(s[i].xi,s[i].xf);
				swap(s[i].yi,s[i].yf);
			}
		}
		sort(s,s+N);
		memset(seg,-1,sizeof seg);
		rp(i,N) {
			if (s[i].equal()) {
				rep[i] = i;
			} else if (s[i].yi < s[i].yf) {
				int k = query(1,1,MAXX,s[i].xf);
				if (k == -1) {
					myx[i] = s[i].xf-1;
					rep[i] = i;
				} else if (s[k].equal()) {
					myx[i] = s[i].xf-1;
					unionSet(i,k);
				} else {
					myx[i] = myx[k];
					unionSet(i,k);
				}
			} else {
				int k = query(1,1,MAXX,s[i].xi);
				if (k == -1) {
					myx[i] = s[i].xi-1;
					rep[i] = i;
				} else if (s[k].equal()) {
					myx[i] = s[i].xi-1;
					unionSet(i,k);
				} else {
					myx[i] = myx[k];
					unionSet(i,k);
				}
			}
			update(1,1,MAXX,s[i].xi,s[i].xf,i);
		}
		int a;
		rp(i,C) {
			scanf("%d", &a); a++;
			int k = query(1,1,MAXX,a);
			if (k == -1) {
				printf("%d\n", a-1);
			} else if (s[k].equal()) {
				printf("%d %d\n", a-1, s[k].yi-1);
			} else {
				printf("%d", myx[k]);
				if (s[findSet(k)].equal()) printf(" %d", s[findSet(k)].yi-1);
				puts("");
			}
		}
	}
	return 0;
}