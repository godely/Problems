#include <bits/stdc++.h>
#define maxn 2000100
 
int size;
struct TNode {
    int x, y, z;
        TNode *L, *R;
        TNode() {}
        TNode(int x, TNode *L, TNode *R) {
                this->x = x;
                this->y = rand();
                this->z = 0;
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
        if (L->y >= R->y) return L->R = merge(L->R,R), fix(L), L;
        else return R->L = merge(L,R->L), fix(R), R;
}
 
void split(Node P, Node &L, Node &R, int x) {
        if (P == nil) return L = nil, R = nil, void();
        if (P->x <= x) return L = P, split(P->R, L->R, R, x), fix(L);
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
        if (x < myx) return kth(P->L,x);
        if (x > myx) return kth(P->R,x-myx);
        return P->x;
}

int main() {
	root = nil;
	srand(time(NULL));
	size = 0;
	while (1) {
		int a;
		scanf("%d", &a);
		if (a >= 0) insert(root,new TNode(a,NULL,NULL));
		else {
			printf("%d\n", kth(root,-a));
		}
	}
}