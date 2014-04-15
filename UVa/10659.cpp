#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) cerr <<#x"=="<<x<<endl;
#define _ << "," <<
#define pb push_back
#define mp make_pair
#define MAXN 1010

vector<int> L[1111111];
char str[11111111];

int main() {
	int T, N, size, count, X, Y;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d\n", &N);
		rp(i,N) L[i].clear();
		rp(i,N) {
			gets(str);
			size = strlen(str);
			count = 0;
			rp(j,size+1) {
				if (str[j] != ' ' && str[j] != '\0') count++;
				else {
					if (count > 0) L[i].push_back(count);
					count = 0;
				}
			}
		}
		scanf("%d%d\n", &X, &Y);
		int ini = 7, fim = 28, meio;
		bool found = 0;
		while (ini != fim) {
			meio = (ini+fim+1)/2;
			bool ok = 1;
			int countY = 0;
			for (int i = 0; i < N && ok; i++) {
				size = L[i].size();
				count = 0;
				countY++;
				rp(j,size) {
					if (meio*L[i][j] > X) {
						ok = 0;
						break;
					}
					if (count+meio*L[i][j] > X) {
						countY++;
						count = meio*(1+L[i][j]);
					} else count += meio*(1+L[i][j]);
				}
				if (meio*countY > Y) {
					ok = 0;
				}
			}
			//printf("%d %d %d %d %d\n", count, countY, ini, fim, ok);
			if (ok) {
				ini = meio;
				found = 1;
			}
			else fim = meio-1;
		}
		if (found) printf("%d\n", ini);
		else printf("No solution\n");
	}
	return 0;
}
