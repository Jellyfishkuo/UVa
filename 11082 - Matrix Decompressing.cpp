#include <bits/stdc++.h>
#define maxn 50+5
#define INF 0x3f3f3f3f
#define rcmax 20+5
using namespace std;

struct Edge{
    int from,to,cap,flow;
};

int n,m,s,t;
vector<Edge> edges;
vector<int> G[maxn];
bool visited[maxn];
int d[maxn];
int cur[maxn];
int M[rcmax][rcmax];

void inti(int n){
    edges.clear();
    for(int i=0;i<n;i++) G[i].clear();
}

void AddEdge(int from,int to,int cap){
    edges.push_back((Edge){from,to,cap,0});
    edges.push_back((Edge){to,from,0,0});
    m=edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

bool bfs(){
    memset(visited,false,sizeof(visited));
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    d[s]=0;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(int i=0;i<G[x].size();i++){
            Edge& e=edges[G[x][i]];
            if(!visited[e.to]&&e.cap>e.flow){
                visited[e.to]=true;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return visited[t];
}

int dfs(int x,int a){
    if(x==t||a==0) return a;
    int flow=0,f;
    for(int& i=cur[x];i<G[x].size();i++){
        Edge& e=edges[G[x][i]];
        if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}

int dinic_maxflow(int s,int t){
    int flow=0;
    while(bfs()){
        memset(cur,0,sizeof(cur));
        flow+=dfs(s,INF);
    }
    return flow;
}

int main(){
    int T,R,C;
    cin>>T;
    int cas=1;
    while(T--){
        cin>>R>>C;
        inti(R+C+1);
        s=0,t=R+C+1;
        int last=0;
        for(int rsum,i=1;i<=R;i++){
            cin>>rsum;
            AddEdge(0,i,rsum-last-C);
            last=rsum;
        }
        last=0;
        for(int csum,i=R+1;i<=R+C;i++){
            cin>>csum;
            AddEdge(i,R+C+1,csum-last-R);
            last=csum;
        }
        for(int r=1;r<=R;r++){
            for(int c=R+1;c<=R+C;c++){
                AddEdge(r,c,19);
                M[r][c]=edges.size()-2;
            }
        }
        dinic_maxflow(s,t);
        cout<<"Matrix "<<cas++<<endl;
        for(int r=1;r<=R;r++){
            for(int c=R+1;c<=R+C;c++){
                cout<<edges[M[r][c]].flow+1<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
