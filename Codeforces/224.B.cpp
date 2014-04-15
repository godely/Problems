#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

bool arr[111111];
bool mark[111111];
int vet[111111];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
    if (k == 1) printf("1 1\n");
    else {
        int a = vet[0];
        arr[a] = 1;
        int i;
        for (i = 0; i < n && vet[i] == a; i++);
        int start = i, end = -1;
        int count = 1;
        for (int j = i; j < n; j++) {
            if (arr[vet[j]]==0) {
                arr[vet[j]]=1;
                count++;
                if (count == k) {
                    end = j+1;
                    break;
                }
            }
        }
        if (end==-1) printf("-1 -1\n");
        else {
            count = 0;
            for (i = end-1; i >= 0; i--) {
                if (!mark[vet[i]]) {
                    mark[vet[i]]=1;
                    count++;
                }
                if (count == k) {
                    start = i+1;
                    break;
                }
            }
            printf("%d %d\n", start, end);
        }
    }
}
