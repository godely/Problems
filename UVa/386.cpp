#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

map<int, vector<pair<int,int> > > mapa;
bool cant[222][222][222];
int main() {
    //printf("xD\n");
    for (int c = 2; c <= 200; c++) {
        for (int d = c; d <= 200; d++) {
            mapa[c*c*c+d*d*d].push_back(make_pair(c,d));
        }
    }

    int c, d;
    for (int a = 2; a <= 200; a++) {
        for (int b = 2; b < a; b++) {
            if (mapa[a*a*a-b*b*b].size() > 0) {
                vector<pair<int, int> > &vec = mapa[a*a*a-b*b*b];
                for (int i = 0; i < vec.size(); i++) {
                    c = vec[i].first, d = vec[i].second;
                    if (!cant[b][c][d]) {
                         printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                         cant[b][c][d]=cant[b][d][c]=cant[c][b][d]=cant[c][d][b]=cant[d][b][c]=cant[d][c][b]=1;
                    }
                }
            }
        }
    }
    return 0;
}
