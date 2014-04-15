#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

int x[10], N;

ll melhorDif, melhorNum;
int melhorNiv;
ll temp[10];
ll tempop[10][4], resop[10][4];

void bt(int niv) {
	int last = 6-niv;
	fr(i,0,last) {
		if (valid[i] && abs(temp[i]-N) < melhorDif) {
			melhorDif = abs(temp[i]-N);
			melhorNum = temp[i];
			melhorNiv = niv;
			rp(j,niv) {
				resop[j][0] = tempop[j][0];
				resop[j][1] = tempop[j][1];
				resop[j][2] = tempop[j][2];
			}
		}
	}
	//printf("(%lld)\n", aux);
	if (last == 1) return;
	
	fr(i,0,last) {
		fr(j,0,last) {
			tempop[niv][0] = temp[i];
			tempop[niv][1] = temp[j];

			temp[i]+=temp[j];
			tempop[niv][2] = 0;
			swap(temp[j],temp[last-1]);
			bt(niv+1);
			swap(temp[j],temp[last-1]);
			temp[i]-=temp[j];
			if (!melhorDif) return;
			
			
			if (temp[i] > temp[j]) {
				temp[i]-=temp[j];
				tempop[niv][2] = 1;
				swap(temp[j],temp[last-1]);
				bt(niv+1);
				swap(temp[j],temp[last-1]);
				temp[i]+=temp[j];
				if (!melhorDif) return;
			}
				
			temp[i]*=temp[j];
			tempop[niv][2] = 2;
			swap(temp[j],temp[last-1]);
			bt(niv+1);
			swap(temp[j],temp[last-1]);
			temp[i]/=temp[j];
			if (!melhorDif) return;
			
			if (temp[i]%temp[j]==0) {
				temp[i]/=temp[j];
				tempop[niv][2] = 3;
				swap(temp[j],temp[last-1]);
				bt(niv+1);
				swap(temp[j],temp[last-1]);
				if (!melhorDif) return;
				temp[i]*=temp[j];
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		rp(i,6) scanf("%d", &x[i]), temp[i] = x[i];
		scanf("%d", &N);
		
		melhorDif = 1000000000000000000LL;
		bt(0);
		printf("Target: %d\n", N);
		rp(i,melhorNiv) {
			if (resop[i][2] == 0) printf("%lld + %lld = %lld\n", resop[i][0], resop[i][1], resop[i][0] + resop[i][1]);
			else if (resop[i][2] == 1) printf("%lld - %lld = %lld\n", resop[i][0], resop[i][1], resop[i][0] - resop[i][1]);
			else if (resop[i][2] == 2) printf("%lld * %lld = %lld\n", resop[i][0], resop[i][1], resop[i][0] * resop[i][1]);
			else if (resop[i][2] == 3) printf("%lld / %lld = %lld\n", resop[i][0], resop[i][1], resop[i][0] / resop[i][1]);
		}
		printf("Best approx: %lld\n", melhorNum);
		printf("\n");
	}
}