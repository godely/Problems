#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string princ;
int totalSize, dp[1010];
vector<string> startsWith[30];
vector<pair<int, int> > ans, resp;

bool match(int ind, int l) {
	string test = startsWith[princ[ind]-97][l];
	int size = test.size();
	if (ind + size > totalSize) return false;
	if (princ[ind+size-1] != test[size-1]) return false;
	int rhs[30], lhs[30];
	memset(rhs, 0, sizeof(rhs));
	memset(lhs, 0, sizeof(lhs));
	for (int i = 0; i < size; i++) {
		rhs[princ[ind+i]-97]++;
		lhs[test[i]-97]++;
	}
	for (int i = 0; i < 27; i++) {
		if (rhs[i] != lhs[i]) return false;
	}
	return true;
}

int solve(int ind) {
	//printf("%d\n", ind);
	if (ind >= totalSize) {
		ans = resp;
		return 1;
	}
	if (dp[ind] != -1) return dp[ind];

	int fL = princ[ind]-97;
	vector<string> &possib = startsWith[fL];
	int size = possib.size();

	int ret = 0;
	for (int i = 0; i < size; i++) {
		if (match(ind, i)) {
			resp.push_back(make_pair(fL,i));
			ret += solve(ind+possib[i].size());
			resp.pop_back();
		}
	}
	return dp[ind] = ret;
}

int main() {
	int T, N;
	string gb;
	scanf("%d", &T);
	while (T--) {
		cin >> princ;
		totalSize = princ.size();
		for (int i = 0; i < 30; i++) startsWith[i].clear();
		scanf("%d", &N);
		while (N--) {
			cin >> gb;
			startsWith[gb[0]-97].push_back(gb);
		}
		memset(dp, -1, sizeof(dp));
		resp.clear();
		int h = solve(0);
		if (!h) printf("impossible\n");
		else if (h == 1) {
			int size = ans.size();
			for (int i = 0; i < size; i++) {
				if (i) cout << " " << startsWith[ans[i].first][ans[i].second];
				else cout << startsWith[ans[i].first][ans[i].second];
			}
			printf("\n");
		} else printf("ambiguous\n");
	}
}