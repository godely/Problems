#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long

using namespace std;

char str[500];
map<string, double> mapa;
map<string, double>::iterator it;
int main() {
    int T;
    scanf("%d\n", &T);
    double size;
    while (T--) {
        mapa.clear();
        size = 0;
        while (gets(str) && str[0] != '\0') {
            if (mapa[str] == 0) {
                mapa[str] = 1;
            } else mapa[str]++;
            size++;
        }
		for (it=mapa.begin(); it != mapa.end(); it++) {
			printf("%s %.4lf\n", (*it).first.c_str(), 100*((*it).second)/size);
		}
        /*while (!heap.empty()) {
            printf("%s %.4lf\n", heap.top().c_str(), 100*mapa[heap.top()]/size);
            heap.pop();
        }*/
        if (T) printf("\n");
    }
    return 0;
}
