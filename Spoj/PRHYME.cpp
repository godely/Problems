#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) Fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

struct TNode {
	int cnt;
	TNode *adj[30];
	string f, s;
	TNode() {
		this->cnt = 0;
		rp(i,26) this->adj[i] = NULL;
		this->f = this->s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	}
	TNode(TNode *q) {
		this->cnt = 0;
		rp(i,26) this->adj[i] = q;
		this->f = this->s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	}
	
	void update(char *c) {
		cnt++;
		string p = c;
		if (p < f) s = f, f = p;
		else if (p < s) s = p;
	}
} *nil = new TNode();
typedef TNode* Node;
Node root;

void insert(Node &P, char *c, int i, int id) {
	if (P == nil) P = new TNode(nil);
	P->update(c);
	if (~i) insert(P->adj[c[i]-'a'], c, i-1, id);
}

map<int, string> n;
bool findLongestSuffix(Node &P, bool matching, char *c, int i) {
	if (matching) {
		if ((~i) && P->adj[c[i]-'a'] != nil && findLongestSuffix(P->adj[c[i]-'a'], 1, c, i-1)) return true;
		return findLongestSuffix(P, 0, c, i);
	} else {
		string p = c;
		if (P->f != p) {
			printf("%s\n", P->f.c_str());
			return true;
		} else if (P->cnt > 1) {
			printf("%s\n", P->s.c_str());
			return true;
		}
	}
	return false;
}

void print(Node &P, string s = "") {
	if (P == nil) return;
	rp(i,26) if (P->adj[i] != nil) printf("%s %c(%d) (%s, %s)\n", s.c_str(), i+'a', P->adj[i]->cnt, P->adj[i]->f.c_str(), P->adj[i]->s.c_str()), print(P->adj[i], s+"	");
}

char str[100];
int main() {
	n.clear();
	int size;
	root = nil;
	int qnt = 1;
	while (gets(str) && (size = strlen(str)) > 0) {
		n[qnt] = str;
		insert(root, str, size-1, qnt++);
	}
	//print(root);
	while (gets(str)) findLongestSuffix(root, 1, str, strlen(str)-1);
	return 0;
}