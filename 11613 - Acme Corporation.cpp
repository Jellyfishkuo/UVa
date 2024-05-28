#include <bits/stdc++.h>
#define int long long
#define maxn 220+10
#define INF 0x3f3f3f3f
using namespace std;

struct Edge{
    int from,to,cap,flow,cost;
};

int n,m,s,t;
vector<Edge> edges;
vector<int> G[maxn];
bool inq[maxn];
int d[maxn],p[maxn],a[maxn];

void AddEdge(int from,int to,int cap,int cost){
    edges.push_back((Edge){from,to,cap,0,cost});
    edges.push_back((Edge){to,from,0,0,-cost});
    m=edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

bool BellmanFord(int s,int t,int& flow,int& cost){
    for(int i=0;i<n;i++) d[i]=INF;
    memset(inq,false,sizeof(inq));
    d[s]=0;inq[s]=true;p[s]=0;a[s]=INF;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        inq[u]=false;
        for(int i=0;i<G[u].size();i++){
            Edge& e=edges[G[u][i]];
            if((e.cap>e.flow)&&(d[e.to]>d[u]+e.cost)){
                d[e.to]=d[u]+e.cost;
                p[e.to]=G[u][i];
                a[e.to]=min(a[u],e.cap-e.flow);
                if(!inq[e.to]){
                    Q.push(e.to);
                    inq[e.to]=true;
                }
            }
        }
    }
    if(d[t]>0) return false;
    flow+=a[t];
    cost+=d[t]*a[t];
    int u=t;
    while(u!=s){
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }
    return true;
}

int Mincostflow(int s,int t){
    int cost=0,flow=0;
    while(BellmanFord(s,t,flow,cost));
    return cost;
}

main(){
    int t,num_month,inventory_cost;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>num_month>>inventory_cost;
        n=2*num_month+2;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
        int s=0,t=n-1;
        for(int i=1;i<=num_month;i++){
            int make_cost,make_max,sell_price,sell_max,inventory_day;
            cin>>make_cost>>make_max>>sell_price>>sell_max>>inventory_day;
            AddEdge(s,i,make_max,make_cost);
            AddEdge(num_month+i,t,sell_max,-sell_price);
            for(int j=0;j<=inventory_day;j++)
                if(i+j<=num_month)
                    AddEdge(i,num_month+i+j,INF,inventory_cost*j);
        }
        cout<<"Case "<<cas<<": "<<-Mincostflow(s,t)<<endl;
    }
    return 0;
}
