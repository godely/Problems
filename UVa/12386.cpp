//TLE
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define maxn 111111
#define inf 1e100

using namespace std;

struct PT {
	double x, y;

	PT() {}
	PT(double x, double y):x(x), y(y) {}


} pts[20];

double area, per, areaper;

PT b[30];
int N, size;
void bt(int mask) {
	if (size >= N) {
		double tempArea = 0, tempPer = 0;
		for (int i = 0, j; i < N; i++) {
			j = (i+1)%N;
			tempArea += b[i].x*b[j].y - b[j].x*b[i].y;
			tempPer += sqrt((b[i].x-b[j].x)*(b[i].x-b[j].x) + (b[i].y-b[j].y)*(b[i].y-b[j].y));
		}
		per = min(tempPer, per);
		tempArea = fabs(tempArea/2.0);
		if (tempArea < area){
			area = tempArea;
			areaper = per;
		}
		return;
	}

	//printf("%d %d\n", mask, size);
	for (int i = 0; i < N; i++) {
		if (!(mask&(1<<i))) {
			b[size++] = pts[i];
			bt(mask|(1<<i));
			size--;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) {
			scanf("%lf%lf", &pts[i].x, &pts[i].y);
		}
		area = per = inf;
		b[0] = pts[0];
		size = 1;
		bt(1);
		printf("%.4lf\n", areaper-per);
	}
}
