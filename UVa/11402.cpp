#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define LSOne(x) (x&(-x))
#define MAXN 1000010

using namespace std;

int vet[1024111], val[1<<22], flag[1<<22];
char str[100];

void build(int R, int l, int r) {
	flag[R] = -2;
	if (l==r) val[R] = vet[l];
	else {
		build(2*R, l, (l+r)/2);
		build(2*R+1, (l+r)/2+1, r);
		val[R] = val[2*R] + val[2*R+1];
	}
}

int newVal(int a, int b) {
	if (~b) return b;
	if (a==-2) return -1;
	else if (a==-1) return 0;
	else return a^1;
}

int _a, _b, _type;
void update(int R, int l, int r) {
	if (flag[R] != -2) {
		if (flag[R] == -1) val[R] = (r-l+1)-val[R];
		else if (flag[R] == 0) val[R] = r-l+1;
		else if (flag[R] == 1) val[R] = 0;
		if (l!=r) flag[2*R] = flag[2*R+1] = _type;
		flag[R]=-2;
	}
	if (r < _a || l > _b) return;
	else if (l >= _a && r <= _b) {
		if (~_type) val[R] = _type*(r-l+1);
		else {
			
		}
		if (l!=r) flag[2*R] = flag[2*R+1] = _type;
		printf("%d %d > %d\n", l, r, val[R]);
	} else {
		if (flag[R]!=-2) {
			if (l!=r) flag[2*R]=newVal(flag[2*R],flag[R]), flag[2*R+1]=newVal(flag[2*R+1],flag[R]);
			flag[R]=-2;
		}
		update(2*R, l, (l+r)/2);
		update(2*R+1, (l+r)/2+1, r);
		//printf(">>> %d %d > %d\n", l, r, val[2*R]+val[2*R+1]);
		val[R] = val[2*R] + val[2*R+1];
	}
}

int query(int R, int l, int r) {
	if (r < _a || l > _b) return 0;
	else {
		if (flag[R] != -2) {
			if (~flag[R]) val[R] = flag[R]*(r-l+1);
			else val[R] = (r-l+1)-val[R];
			if (l!=r) flag[2*R]=newVal(flag[2*R],flag[R]), flag[2*R+1]=newVal(flag[2*R+1],flag[R]);
			flag[R]=-2;
		}

		if (l >= _a && r <= _b) return val[R];
		return query(2*R, l, (l+r)/2) + query(2*R+1, (l+r)/2+1, r);
	}
}

int main() {
	int T, M, N, K, size, q;
	scanf("%d", &T);
	fr(cas,1,T+1) {
		N = 1;
		scanf("%d", &M);
		while(M--) {
			scanf("%d%s", &K, str);
			size = strlen(str);
			while(K--) {
				rp(i,size) {
					vet[N++] = (str[i]=='1');
				}
			}
		}
		N--;
		build(1,1,N);
		printf("Case %d:\n", cas);
		q = 1;
		scanf("%d", &M);
		while(M--) {
			scanf("%s%d%d", str, &_a, &_b);
			_a++, _b++;
			if (str[0] == 'F') _type = 1, update(1,1,N);
			else if (str[0] == 'E') _type = 0, update(1,1,N);
			else if (str[0] == 'I') _type = -1, update(1,1,N);
			else printf("Q%d: %d\n", q++, query(1,1,N));
		}
	}
}