#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
 
using namespace std;
 
int pos[100010];
int pai[100010];
int lis[100010];
int A[100010];
int n;
int dolis(int z = 0) {
	for(int i = 0; i < n; ++i) {
		int num = A[i];
		int x = lower_bound(lis,lis+z,num)-lis;
		if(x == z) ++z;
		lis[x]=num;
		pai[i] = x ? pos[x-1] : -1;
		pos[x]=i;
	}
	return z;
}
 
vector<int> lol;
int main () {
        //freopen("in.txt","r",stdin);
        n=0;
        for(int i = 0; scanf("%d",&A[i]) != EOF; ++i) ++n;
        int x = dolis();
        printf("%d\n",x);
        printf("-\n");
        int now = pos[x-1];
		while (now != -1) {
			lol.pb(A[now]);
			now=pai[now];
		}
		for (int i = x-1; i >= 0; i--) printf("%d\n", lol[i]);
        //while(1);
        return 0;
}