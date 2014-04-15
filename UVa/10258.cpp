#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
using namespace std;

struct TEAM {
    int points;
    bool ac[10];
    int wa[10];
    int accs, id;

    TEAM() {}
    TEAM(int id) : id(id) {
        points = accs = 0;
        memset(ac,0,sizeof ac);
        memset(wa,0,sizeof wa);
    }

    bool operator<(const TEAM &lhs) const {
        if (accs != lhs.accs) return accs > lhs.accs;
        if (points != lhs.points) return points < lhs.points;
        return id < lhs.id;
    }
} team[111];

int id[111], k;

char str[111], L[10], t;
int main() {
    int T, time, prob, tempo;
    scanf("%d\n", &T);
    while (T--) {
        k = 0;
        memset(id,-1,sizeof id);
        while (gets(str) && strlen(str) > 2) {
            sscanf(str, "%d %d %d %s", &time, &prob, &tempo, L);
            if (id[time]==-1) team[k] = TEAM(time), id[time] = k++;
            t = id[time];
            if (team[t].ac[prob]) continue;

            //printf("%d %d %d %d\n", time, prob, tempo, team[t].wa[prob]);
            if (L[0]=='I') team[t].wa[prob]++;
            else if (L[0] == 'C') team[t].ac[prob]=1, team[t].points+=20*team[t].wa[prob]+tempo, team[t].accs++;
            //printf("%d\n", team[t].accs);
        }
        sort(team,team+k);
        rp(i,k) printf("%d %d %d\n", team[i].id, team[i].accs, team[i].points);
        if (T) printf("\n");
    }
    return 0;
}
