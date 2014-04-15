#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define fm(a,b,c,d) for(int a=b;a<c;a+=d)
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
#define inf 0x3f3f3f3f

int win[] = {7,56,73,84,146,273,292,448};
int dp[513][513][2];

int isWinning(int used, int mask, int jog) {
	if (dp[used][mask][jog] != inf) return dp[used][mask][jog];

	for (int i = 0; i < 8; i++) {
		if ((used&win[i]) == win[i]) {
			if ((mask&win[i]) == win[i]) {
				//printf("%d %d %d\n", used, mask, jog);
				return 1;
			}
			else if ((mask&win[i]) == 0) return 0;
		}
	}
	if ((used&511) == 511) {
		return -1;
	}

	int k;
	int resposta = jog^1, retorno;
	for (int i = 0; i < 9; i++) {
		k = (1<<i);
		if (!(used&k)) {
			retorno = isWinning(used|k, mask|(k*jog), jog^1);
			//if (used == 467 && mask == 131) printf("%d (%d %d %d)\n", retorno, used, mask, jog);
			if (resposta != jog) {
				if (retorno == jog) resposta = jog;
				else if (retorno == -1) resposta = -1;
			}
		}
	}
	return dp[used][mask][jog] = resposta;
}

char str[15];
struct jogo{
	int r1,r2,ind;
	int count;
	jogo(int r1=0,int r2=0,int ind=0):r1(r1),r2(r2),ind(ind) {
		if(r1==0&&r2==1) count=0;
		else if((r1==0&&r2==-1)||(r1==-1&&r2==1)) count=1;
		else count=2;
	}
	bool operator<(const jogo &lhs)const{
		return count < lhs.count;
	}
}joao[1001],maria[1001];
bool pode[1001];
int main() {
	cl(dp,0x3f);
	isWinning(0,0,0);
	isWinning(0,0,1);
	int N, u, m;
	int cas=1;
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) {
			scanf("%s", str);
			u = 0;
			m = 0;
			rp(j,9) {
				if (str[j] != '.') {
					u |= (1<<j);
					m |= ((str[j]=='X')<<j);
				}
			}
			//printf("%d %d\n", u, m);
			maria[i]=jogo(isWinning(u,m,0), isWinning(u,m,1), i);
			int novo=dp[u][m][1],novo2=dp[u][m][0];
			if(novo==1) novo=0;
			else if(novo==0) novo=1;
			if(novo2==1 ) novo2=0;
			else if(novo2==0) novo2=1;
			joao[i]=jogo(novo,novo2,i);
			//printf("%d %d\n", dp[u][m][0], dp[u][m][1]);
		}
		sort(maria,maria+N);
		sort(joao,joao+N);
		int ans=0,ct=0,k=0,p=0;
		cl(pode,0);
		while(ct<N){
			while(pode[joao[p].ind]) p++;
			pode[joao[p].ind]=true;
			while(pode[maria[k].ind]) k++;
			pode[maria[k].ind]=true;
			if(maria[k].r1==0) ans--;
			else if(maria[k].r1==1) ans++;
			if(joao[p].r1==0) ans++;
			else if(joao[p].r1==1) ans--;
			ct+=2;
		}
		printf("Case %d: ",cas++);
		if(ans<0) printf("Mary wins.\n");
		else if ( ans>0 ) printf("Johnny wins.\n");
		else printf("Draw.\n");
	}
	return 0;
}
