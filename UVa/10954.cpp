#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define top() xD.top(); xD.pop()
#define LL long long

using namespace std;

int main() {
    int N;
    LL a, b, c;
    priority_queue<LL, vector<LL>, greater<LL> > xD;
    while (scanf("%d", &N) == 1 && N > 0) {
        rp(i,N) scanf("%lld", &a), xD.push(a);
        c = 0;
        while (xD.size() > 1) {
            a = top();
            b = top();
            c += a+b;
            xD.push(a+b);
        }
        xD.pop();
        printf("%lld\n", c);
    }
    return 0;
}
