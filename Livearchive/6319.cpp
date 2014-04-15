#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 1000100

int size;

struct TNode {
	int x, y, z;
	char c;
	TNode *L, *R;
	TNode() {}
	TNode(int x, TNode *L, TNode *R, char c = 0) {
		this->x = x;
		this->y = rand();
		this->z = 0;
		this->c = c;
		this->L = L;
		this->R = R;
	}
} *nil = new TNode(0,NULL,NULL), node[maxn];
typedef TNode* Node;
Node root;

void fix(Node &P) { if (P != nil) P->z = P->L->z + P->R->z + 1; }

Node merge(Node L, Node R) {
	if (L == nil) return R;
	else if (R == nil) return L;
	if (L->y >= R->y) return (L->R = merge(L->R,R), fix(L), L);
	else return (R->L = merge(L,R->L), fix(R), R);
}

void split(Node P, Node &L, Node &R, int x) {
	if (P == nil) return L = nil, R = nil, void();
	int a = P->L->z + 1;
	if (a <= x) return L = P, split(P->R, L->R, R, x-a), fix(L);
	return R = P, split(P->L, L, R->L, x), fix(R);
}

void insert(Node &P, Node novo) {
	if (P == nil || novo->y >= P->y) split(P, novo->L, novo->R, novo->x), P = novo;
	else if (novo->x < P->x) insert(P->L, novo);
	else insert(P->R, novo);
	fix(P);
}

void remove(Node &P, int x) {
	if (P->x == x) return P = merge(P->L, P->R), fix(P);
	if (x < P->x) remove(P->L,x), fix(P);
	else remove(P->R,x), fix(P);
}

int kth(Node P, int x) {
	int myx = P->L->z + 1;
	if (x < myx) return kth(P->L, x);
	if (x > myx) return kth(P->R, x-myx);
	return P->x;
}

void print(Node P, string s = "", char from = '-') {
	if (P == nil) return;
	printf("%s%c: %c\n", s.c_str(), from, P->c);
	print(P->L, s+"	", 'L');
	print(P->R, s+"	", 'R');
}

void print(int ini, int fim) {
	for (int i = ini; i <= fim; i++) {
		int k = kth(root, i);
		printf("%c", node[k].c);
	}
	printf("\n");
}

char str[maxn], cmd[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		srand(time(NULL));
		size = 0;
		root = nil;
		scanf("%s", str);
		for (int i = 0; str[i]; i++) {
			node[size] = TNode(size, NULL, NULL, str[i]);
			insert(root, node+size++);
		}
		while (scanf("%s", cmd) == 1 && cmd[0] != 'E') {
			if (cmd[0] == 'I') {
				int a;
				scanf("%s%d", cmd, &a);
				Node newTree = nil;
				for (int i = 0; cmd[i]; i++) {
					node[size] = TNode(size, NULL, NULL, cmd[i]);
					insert(newTree, node+size++);
				}
				Node tempL = nil, tempR = nil;
				split(root, tempL, tempR, a);
				root = merge(merge(tempL, newTree), tempR);
			} else {
				int a, b;
				scanf("%d%d", &a, &b);
				print(a+1,b+1);
			}
		}
	}
}