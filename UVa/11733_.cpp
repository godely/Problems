#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#define REP(i,a,b) for (int i = (a); i < (b); ++i)

using namespace std;

typedef vector<int> vi;

vi pset;

void initSet(int n) {
	pset.assign(n,0);
	for(int i = 0; i < n; ++i) pset[i] = i;
}

int findSet(int a) {
	return (pset[a] == a) ? a : (pset[a] = findSet(pset[a]));
}

bool isSameSet(int a, int b) {
	return findSet(a) == findSet(b);
}

void unionSet(int a, int b) {
	pset[findSet(a)] = findSet(b);
}

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<iii> EdgeList;

int main () {
	int TC,N,M,A;
	scanf("%d",&TC);
	for (int cases = 1; TC--; ++cases) {
		scanf("%d %d %d",&N, &M, &A);
		EdgeList.clear();
		initSet(N);
		REP(i,0,M) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if (c < A) {
				EdgeList.push_back(make_pair(c,ii(a-1,b-1)));
			}
		}
		sort(EdgeList.begin(),EdgeList.end());
		int mst_cost = 0;
		int qtd = 0;
		REP(i,0,EdgeList.size()) {
			iii front = EdgeList[i];
			if (!isSameSet(front.second.first,front.second.second)) {
				unionSet(front.second.first,front.second.second);
				mst_cost+=front.first;
				++qtd;
			}
		}
		printf("Case #%d: %d %d\n",cases, mst_cost+((N-qtd)*A),(N-qtd));
	}
	return 0;
}
