#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXM 50000
#define INF 999999999

int n, m;
int cam[510][510];
void fw() { rp(r,n) rp(i,n) rp(j,n) cam[i][j] = min(cam[i][j],cam[i][r]+cam[r][j]); }
map<string,int> s;
int k;
int main(void) {
    int cas = 1;
    string a, b;

    while (cin >> n >> m) {
        if (!n && !m) break;
		s.clear(); k = 0;

        rp(i,n) rp(j,n) {
			if (i == j) cam[i][j] = 0;
			else cam[i][j] = INF;
        }

        rp(i,m) {
			cin >> a >> b;
			if (s.find(a) == s.end()) s[a] = k++;
			if (s.find(b) == s.end()) s[b] = k++;
			cam[s[a]][s[b]] = cam[s[b]][s[a]] = 1;
		}

        fw();
		int custo = -1;
		printf("Network %d: ", cas++);
		rp(i,n) rp(j,n) custo = max(custo,cam[i][j]);
		if (custo >= INF) printf("DISCONNECTED\n\n");
		else printf("%d\n\n", custo);
    }

    return 0;
}

