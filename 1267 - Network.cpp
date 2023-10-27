#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

vector<int> g[maxn],nodes[maxn];
int n,s,k,p[maxn];
bool c[maxn];

void dfs1(int u,int f,int dist){
    p[u]=f;
    int nd=g[u].size();
    if(nd==1&&dist>k)
        nodes[dist].push_back(u);
    for(int i=0;i<nd;i++){
        int v=g[u][i];
        if(v!=f) dfs1(v,u,dist+1);
    }
}

void dfs2(int u,int f,int d){
    c[u]=true;
    int nd=g[u].size();
    for(int i=0;i<nd;i++){
        int v=g[u][i];
        if(v!=f&&d<k) dfs2(v,u,d+1);
    }
}

int solve(){
    int ans=0;
    memset(c,false,sizeof(c));
    for(int dist=(n-1);dist>k;dist--){
        for(int i=0;i<nodes[dist].size();i++){
            int u=nodes[dist][i];
            if(c[u]) continue;
            int v=u;
            for(int j=0;j<k;j++) v=p[v];
            dfs2(v,-1,0);
            ans++;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>s>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
            nodes[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs1(s,-1,0);
        cout<<solve()<<endl;
    }
    return 0;
}
