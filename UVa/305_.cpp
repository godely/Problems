//for printing :)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define prox(i) (i+1)%N
#define ant(i) (i+N-1)%N

using namespace std;

int res[] =
{0,
2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881};

int main() {
	int N;
	while (scanf("%d", &N) == 1 && N > 0) printf("%d\n", res[N]);
	return 0;
}