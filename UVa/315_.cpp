#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define INF 2000000000
#define MOD 1000000007

bool visit[110];
vector<long>edge[110];
int n;

void dfs(int node)
{
    visit[node]=true;
    for(int j=0;j<edge[node].size();j++)
        if(!visit[edge[node][j]])
            dfs(edge[node][j]);
}

int Articulation_point()
{
    for(int i=1;i<=n;i++)
        if(!visit[i])
            return 1;
    return 0;
}


int main()
{
    int i, f, t,ans;
    string line;
    //READ("input.txt");
    //WRITE("a.txt");
    while(cin>>n)
    {
        if(n==0)
            break;


        if(n==1)
            {
                cin>>f;
                cout<<"0"<<endl;
                continue;
            }
        getchar();


        while(getline(cin,line))
        {
            istringstream ss(line);
            ss>>f;
            if(f==0)
                break;
            while(ss>>t)
            {
                edge[f].PB(t);
                edge[t].PB(f);
            }
        }

        ans=0;

        for(i=2;i<=n;i++)
        {
            CLR(visit);
            visit[i]=true;
            dfs(1);
			if (Articulation_point()) ans+=1, printf("> %d\n", i);
        }

        CLR(visit);
        visit[1]=true;
        dfs(2);
        ans+=Articulation_point();

        cout<<ans<<endl;

        for(i=1;i<=n;i++)
            edge[i].clear();
    }
return 0;
}