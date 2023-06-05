#include<bits/stdc++.h>
#define maxn 2000+5
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
    int v,w;
};

int n,m;
vector<edge> G[maxn];

bool SPFA(int s){
    int cnt[maxn];
    int dist[maxn];
    bool inqueue[maxn];
    queue<int> q;
    memset(cnt,0,sizeof(cnt));
    memset(dist,INF,sizeof(dist));
    memset(inqueue,0,sizeof(inqueue));
    q.push(s);
    dist[s]=0;
    inqueue[s]=1;
    cnt[s]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        inqueue[now]=0;
        for(auto &e:G[now]){
            if(dist[e.v]>dist[now]+e.w){
                dist[e.v]=dist[now]+e.w;
                if(!inqueue[e.v]){
                    if(++cnt[e.v]>=n) return 0;
                    q.push(e.v);
                    inqueue[e.v]=1;
                }
            }
        }
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++) G[i].clear();
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            G[u].push_back({v,w});
        }
        if(!SPFA(0)) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
}
