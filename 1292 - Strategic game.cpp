#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,u,m,v;
int dp[2000][2000];
vector<vector<int>> G;

void dfs(int u,int p){
    for(int v:G[u]){
        if(v!=p){
            dfs(v,u);
            dp[u][0]+=dp[v][1];
            dp[u][1]+=min(dp[v][0],dp[v][1]);
        }
    }
    dp[u][1]++;
}

main(){
    while(cin>>n){
        memset(dp,0,sizeof(dp));
        G.assign(n+5,vector<int>());
        for(int i=0;i<n;i++){
            scanf("%lld:(%lld)",&u,&m);
            for(int j=0;j<m;j++){
                cin>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        dfs(0,-1);
        cout<<min(dp[0][0],dp[0][1])<<endl;
    }
    return 0;
}
