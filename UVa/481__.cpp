#include <cstdio>
#include <algorithm>

using namespace std;


int lis[100010];
int pai[100010];
int A[100010];
int n;
int dolis(int z = 0) {
	for(int i = 0; i < n; ++i) {
		int num = A[i];
		int x = lower_bound(lis,lis+z,num)-lis;
		if(x == z) ++z;
		lis[x]=num;
		pai[x] = x ? lis[x-1] : -1;
	}
	return z;
}

int main () {
	//freopen("in.txt","r",stdin);
	n=0;
	for(int i = 0; scanf("%d",&A[i]) != EOF; ++i) ++n;
	int x = dolis();
	printf("%d\n",x);
	printf("-\n");
	for(int i = 1; i < x; ++i) printf("%d\n",pai[i]);
	printf("%d\n",lis[x-1]);
	//while(1);
	return 0;
}