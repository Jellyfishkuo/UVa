#include <bits/stdc++.h>
#define maxn 1000+10
using namespace std;

int n,m;
int x[maxn],y[maxn],p[maxn];
double maxcost[maxn][maxn];
vector<int> visited;

struct Edge{
    int u,v;
    double cost;
    bool operator<(const Edge &a)const{
        return cost<a.cost;
    }
}e[maxn*maxn];

vector<Edge> G[maxn];
int parent[maxn];

int find(int x){
    return x == parent[x] ? x : parent[x]=find(parent[x]);
}

bool uni(int a,int b){
    int x=find(a),y=find(b);
    if(x==y) return false;
    parent[x]=y;
    return true;
}

double dist(int a,int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

double kruskal(){
    m=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            e[m++]=(Edge){i,j,dist(i,j)};
    sort(e,e+m);
    for(int i=0;i<n;i++){
        parent[i]=i;
        G[i].clear();
    }
    double mst_cost=0.0;
    int edge_cnt=0;
    for(int i=0;i<m;i++){
        int u=e[i].u, v=e[i].v;
        double c=e[i].cost;
        if(uni(u,v)){
            G[u].push_back((Edge){u,v,c});
            G[v].push_back((Edge){v,u,c});
            mst_cost+=c;
            if(++edge_cnt==n-1) break;
        }
    }
    return mst_cost;
}

void dfs(int u,int v,double w){
    for(int x=0;x<visited.size();x++)
        maxcost[x][v]=maxcost[v][x]=max(maxcost[x][u],w);
    visited.push_back(v);
    for(int i=0;i<G[v].size();i++){
        int next_v=G[v][i].v;
        if(next_v==u) continue;
        dfs(v,next_v,G[v][i].cost);
    }
}

void find_path_max(){
    memset(maxcost,0,sizeof(maxcost));
    visited.clear();
    dfs(-1,0,0.0);
}

void solve(){
    double min_cost=kruskal();
    find_path_max();
    double ans=-1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            ans=max(ans,(p[i]+p[j])/(min_cost-maxcost[i][j]));
    cout<<fixed<<setprecision(2)<<ans<<endl;
}

int main(){
    int Case;
    cin>>Case;
    while(Case--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>p[i];
        solve();
    }
    return 0;
}
