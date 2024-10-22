#include <bits/stdc++.h>
#define maxn 510
#define INF 0x3f3f3f3f
using namespace std;

int dp[maxn][maxn][2],d[maxn],tc[maxn],n;
vector<int> G[maxn];

void dfs(int u)
{
    tc[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        dfs(v);
        tc[u]+=tc[v];
    }
    dp[u][1][0]=dp[u][1][1]=0;
    for(int i=2;i<=tc[u];i++)
        dp[u][i][0]=dp[u][i][1]=INF;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        for(int j=tc[u];j>=2;j--)
        {
            for(int k=0;k<=j,k<=tc[v];k++)
            {
                dp[u][j][1]=min(dp[u][j][1],dp[u][j-k][1]+dp[v][k][1]+2*d[v]);
                dp[u][j][0]=min(dp[u][j][0],dp[u][j-k][1]+dp[v][k][0]+d[v]);
                dp[u][j][0]=min(dp[u][j][0],dp[u][j-k][0]+dp[v][k][1]+2*d[v]);
            }
        }
    }
}


int main()
{
    int cas=0;
    while(cin>>n&&n)
    {
        for(int i=0;i<=n;i++) G[i].clear();
        memset(tc,0,sizeof(tc));
        memset(dp,0,sizeof(dp));
        memset(d,0,sizeof(d));
        for(int i=1;i<=n-1;i++)
        {
            int u,v,w;
            cin>>v>>u>>w;
            G[u].push_back(v);
            d[v]=w;
        }
        dfs(0);

        int q;
        cin>>q;
        cout<<"Case "<<++cas<<":\n";
        while(q--)
        {
            int k,ans=0;
            cin>>k;
            for(int i=n;i>=1;i--)
            {
                if(k>=dp[0][i][0])
                {
                    ans=i;
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}


/*
3
1 0 5
2 0 3
3
3
10
11
0

*/
