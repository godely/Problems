#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define mp make_pair

char str[1100000];
map< pair<int,int>, char> M;
int num, tam;

int main() {
	while (gets(str)) {
		int num = 0, tam = 1;
		M.clear();
		for (int i = 0; str[i]; i++) {
			M[mp(tam,num)] = str[i];
			//printf("> %d %d, %c\n", num, tam, str[i]);
			num++;
			if (__builtin_popcount(num) == tam) tam++, num = 0;
		}
		num = tam = 0;
		int cnt = 0, st = 0;
		while (gets(str)) {
			for (int i = 0; str[i]; i++) {
				if (st < 3) {
					tam<<=1;
					tam+=str[i]-'0';
					st++;
				} else {
					if (tam == 0) {
						goto fim;
					}
					if (cnt < tam) {
						num<<=1;
						num+=str[i]-'0';
						cnt++;
					}
					if (cnt == tam) {
						if (__builtin_popcount(num) == tam) {
							num = tam = cnt = st = 0;
						} else {
							printf("%c", M[mp(tam,num)]);
							num = cnt = 0;
						}
					}
				}
			}
			if (st == 3 && tam == 0) break;
		}
		fim:;
		puts("");
	}
	return 0;
}