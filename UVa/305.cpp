//really fast :D
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define prox(i) (i+1)%N
#define ant(i) (i+N-1)%N

using namespace std;

int passo=0;
vector<int> v;
int main() {
    int K, N, m, j, c;
    while (scanf("%d", &K) == 1 && K > 0) {
        N = 2*K;
        for (int i = 1; i <= 30000000; i++) {
			//if (i%1000==0) printf("%d\n", i);
			v.clear();
            for (j = 0; j < N; j++) v.push_back(j);
            j = 0, m = 0;
            while (1) {
				j = (j+i-1)%(N-m);
				//printf("%d %d %d\n", N-m, j, i);
				if (v[j] < K) break;
                v.erase(v.begin()+j);
                m++;
                if (m >= K) {
                    printf("%d\n", i);
                    goto lol;
                }
            }
            //printf("\n");
        }
        lol:;
    }
    return 0;
}