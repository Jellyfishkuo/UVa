#include <bits/stdc++.h>
#define int long long
#define maxn 100+5
using namespace std;

int d[maxn][maxn][2];
int G[maxn][maxn];
int n,r;

struct node{
    int u,cost;
    bool operator<(const node &a)const{
        return cost>a.cost;
    }
};

void dijkstra(int s){
    priority_queue<node> pq;
    for(int i=0;i<n;i++)
        if(G[s][i]) pq.push({i,G[s][i]});
    node tmp;
    while(!pq.empty()){
        tmp=pq.top();
        pq.pop();
        int u=tmp.u;
        int cost=tmp.cost;
        if(d[s][u][0]==0) d[s][u][0]=cost;
        else{
            if(d[s][u][0]>cost){
                d[s][u][1]=d[s][u][0];
                d[s][u][0]=cost;
            }
            else if(d[s][u][0]==cost) continue;
            else if(d[s][u][1]==0||d[s][u][1]>cost) d[s][u][1]=cost;
            else continue;
        }
        for(int i=0;i<n;i++)
        if(G[u][i]) pq.push({i,G[u][i]+cost});
    }
}

main(){
    int t=0;
    while(cin>>n>>r){
        int u,v,w;
        memset(G,0,sizeof(G));
        for(int i=0;i<r;i++){
            cin>>u>>v>>w;
            G[u][v]=w;
            G[v][u]=w;
        }
        cout<<"Set #"<<++t<<endl;
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++) dijkstra(i);
        int a,b,cas;
        cin>>cas;
        for(int i=0;i<cas;i++){
            cin>>a>>b;
            if(a!=b){
                if(d[a][b][1]) cout<<d[a][b][1]<<endl;
                else cout<<"?\n";
            }
            else{
                if(d[a][b][0]) cout<<d[a][b][0]<<endl;
                else cout<<"?\n";
            }
        }
    }
    return 0;
}
