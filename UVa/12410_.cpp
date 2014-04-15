#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define ll long long

using namespace std;

ll s, t, one, ideal, diff;
int lim[40], id[40];
ll dp[40][40][40][21][2];
ll way[40][40][40][21][2];

ll solve(ll l){
    rep(i, 32) lim[i] = l % 2, l /= 2;
    reverse(lim, lim + 32);

    memset(dp, 0, sizeof(dp));
    memset(way, 0, sizeof(way));

    way[0][0][0][0][0] = 1;
    rep(i, 32) rep(j, one + 1) rep(k, diff + 1) rep(l, 21) rep(m, 2){
        if(way[i][j][k][l][m]) rep(nxt, 2){

            if(!m && nxt > lim[i]) continue;
            int nj = j + nxt;
            int nk = k + (id[i] != nxt);
            int nl = (l * 2 + nxt) % 21;
            int nm = m || nxt < lim[i];

            if(nj > one || nk > diff) continue;

            dp[i + 1][nj][nk][nl][nm] += dp[i][j][k][l][m] * 2 + nxt * way[i][j][k][l][m];
            way[i + 1][nj][nk][nl][nm] += way[i][j][k][l][m];
        }
    }
    ll ans = 0;
    rep(i, one + 1) rep(j, diff + 1) rep(k, 21) rep(l, 2){

        if(k % 3 == 0 && k % 7)
        ans += dp[32][i][j][k][l];
    }
    return ans;
}

int main()
{
    int CS;
    cin >> CS;
    rep(cs, CS){
        cin >> s >> t >> one >> ideal >> diff;

        one = min(one, 33ll);
        diff = min(diff, 33ll);

        rep(i, 32) id[i] = ideal % 2, ideal /= 2;
        reverse(id, id + 32);

        ll ans = solve(t) - solve(s - 1);
        printf("Case %d: %lld\n", cs + 1, ans);
    }
    return 0;
}
