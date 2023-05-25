#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

int n;
int dp[maxn][2];
vector<int> G[maxn];

void dfs(int u,int pa){
    dp[u][0]=dp[u][1]=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pa) continue;
        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
    dp[u][1]++;
}

int main(){
    while(cin>>n,n){
        for(int i=0;i<=n;i++) G[i].clear();
        for(int u=1;u<=n;u++){
            int k,v;
            cin>>k;
            while(k--){
                cin>>v;
                G[u].push_back(v);
            }
        }
        if(n==1){
            cout<<"1\n";
            continue;
        }
        dfs(1,-1);
        cout<<min(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}

