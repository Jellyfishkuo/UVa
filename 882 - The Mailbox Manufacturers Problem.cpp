#include <bits/stdc++.h>
#define maxk 15
#define maxm 105
#define INF 0x3f3f3f3f
using namespace std;

int dp[maxk][maxm][maxm];
bool vis[maxk][maxm][maxm];

int dfs(int k,int i,int j)
{
    if(i>j) return 0;
    if(k==0) return INF;
    if(vis[k][i][j]) return dp[k][i][j];
    vis[k][i][j]=true;
    int &ret=dp[k][i][j];
    ret=INF;
    for(int x=i;x<=j;x++)
        ret=min(ret,x+max(dfs(k-1,i,x-1),dfs(k,x+1,j)));
    return ret;

}

int main()
{
    int cas,k,m;
    memset(vis,0,sizeof(vis));
    cin>>cas;
    while(cas--)
    {
        cin>>k>>m;
        cout<<dfs(k,1,m)<<endl;
    }
    return 0;
}

/*
4
1 10
1 100
3 73
5 100

*/
