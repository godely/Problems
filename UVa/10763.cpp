#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

map< pair<int, int> , int> F;
map< pair<int, int> , int>::iterator it;
int main() {
    int N, a, b;
    bool can;
    while (scanf("%d", &N) == 1 && N != 0) {
        F.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a, &b);
            F[make_pair(a,b)]++;
        }
        can = true;
        for (it=F.begin(); it != F.end(); it++) {
            if (F[make_pair((*it).first.second ,(*it).first.first)] != (*it).second) {
                can = false;
                break;
            }
        }
        if (can) printf("YES\n");
        else printf("NO\n");
    }
}