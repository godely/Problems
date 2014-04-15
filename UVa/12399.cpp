#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define LL long long

using namespace std;

int vet[4][4];
void unfix(int i, int j, int k) {
    vet[i][j] = (vet[i][j]+1)%10;
    if (i-1 >= 0) vet[i-1][j] = (vet[i-1][j]+k+10)%10;
    if (i+1 < 3) vet[i+1][j] = (vet[i+1][j]+k+10)%10;
    if (j-1 >= 0) vet[i][j-1] = (vet[i][j-1]+k+10)%10;
    if (j+1 < 3) vet[i][j+1] = (vet[i][j+1]+k+10)%10;
}

map<LL, int> mark;
map<LL, string> lol;
void bfs() {
    queue<pair<LL, string> > fila;
    fila.push(make_pair(0, ""));
    mark[0] = 1;
    LL hash;
    pair<LL, string> aux;
    int k = 0;
    while(!fila.empty()) {
        if (k > 100000) break;
        k++;
        aux = fila.front();
        fila.pop();
        hash = aux.first;
        lol[hash] = aux.second;
        //printf("%lld\n", hash);
        rp(i,3) {
            rp(j,3) {
                vet[2-i][2-j] = hash%10;
                hash/=10;
            }
        }

        rp(i,3) {
            rp(j,3) {
                unfix(i,j,1);
                hash = 0;
                rp(a,3) rp(b,3) {
                    hash*=10;
                    hash+=vet[a][b];
                }
                unfix(i,j,-1);
                if (mark[hash]==0) {
                    mark[hash] = 1;
                    fila.push(make_pair(hash, aux.second + "abcdefghi"[i*3+j]));
                }
            }
        }
    }
}

char aff1[111], aff2[1111];
int main() {
    bfs();
    printf("xD\n");
    int a;
    LL hash;
    while (scanf("%s%s", aff1, aff2) == 2) {
        hash = 0;
        rp(i,3) rp(j,3) {
            scanf("%d", &a);
            hash*=10;
            hash+=a;
        }
        if (mark[hash]==0) printf("No solution.\n");
        else printf("%s\n", lol[hash].c_str());
    }
    return 0;
}
