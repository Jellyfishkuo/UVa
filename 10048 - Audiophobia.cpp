#include<bits/stdc++.h>
#define maxn 301
#define int long long
using namespace std;

typedef struct _edge{
    int from,to,weight;
    _edge(){};
    _edge(int u,int v,int w):from(u),to(v),weight(w){};
} Edge;

typedef pair<int,int> ii;

class Graph{
private:
    int num_vertex;
    int AdjMatrix[maxn][maxn]={{0}};
    vector<ii> MST[maxn];
    int vset[maxn]={0};

public:
    Graph(int n):num_vertex(n){};
    void AddEdge(int from,int to,int weight);
    void EdgeSort(vector<Edge> &edge_vec);
    friend int FindParent(int *vset,int i);
    friend void SetUnion(int *vset,int x,int y);
    void Kruskal();
    int DFSUtil(int s,int d,bool visited[],bool* found);
    int DFS(int s,int d);
};

int FindRoot(int *vset,int i){
    int root;
    for(root=i;vset[root]>=0;root=vset[root]);
    while(i!=root){
        int parent=vset[i];
        vset[i]=root;
        i=parent;
    }
    return root;
}

void SetUnion(int *vset,int a,int b){
    int a_root,b_root;
    a_root=FindRoot(vset,a);
    b_root=FindRoot(vset,b);
    if(vset[a_root]<=vset[b_root]){
        vset[a_root]+=vset[b_root];
        vset[b_root]=a_root;
    }
    else{
        vset[b_root]+=vset[a_root];
        vset[a_root]=b_root;
    }
}

bool WComp(Edge e1,Edge e2){
    return (e1.weight<e2.weight);
}

void Graph::EdgeSort(vector<Edge> &edge_vec){
    for(int i=1;i<=num_vertex;i++)
        for(int j=i+1;j<=num_vertex;j++)
            if(AdjMatrix[i][j]!=0) edge_vec.push_back(Edge(i,j,AdjMatrix[i][j]));
    sort(edge_vec.begin(),edge_vec.end(),WComp);
}

void Graph::AddEdge(int from,int to,int weight){
    AdjMatrix[from][to]=weight;
    AdjMatrix[to][from]=weight;
}

void Graph::Kruskal(){
    int edge_count=0;
    for(int i=1;i<=num_vertex;i++) vset[i]=-1;
    vector<Edge> SortedEdge;
    EdgeSort(SortedEdge);
    for(int i=0;i<SortedEdge.size();i++)
    if(FindRoot(vset,SortedEdge[i].from)!=FindRoot(vset,SortedEdge[i].to)){
        MST[SortedEdge[i].from].push_back(make_pair(SortedEdge[i].to,SortedEdge[i].weight));
        MST[SortedEdge[i].to].push_back(make_pair(SortedEdge[i].from,SortedEdge[i].weight));
        SetUnion(vset,SortedEdge[i].from,SortedEdge[i].to);
        edge_count++;
        if(edge_count==(num_vertex-1)) break;
    }
}

int Graph::DFSUtil(int s,int d,bool visited[],bool* found){
    visited[s]=true;
    int m=0;
    vector<ii>::iterator i;
    for(i=MST[s].begin();i!=MST[s].end();i++){
        if(!visited[(*i).first] && (*i).first==d){
            *found=true;
            return ((*i).second);
        }
        else if(!visited[(*i).first]){
            m=DFSUtil((*i).first,d,visited,found);
            if(*found) return (m>(*i).second ? m : (*i).second);
        }
    }
    if(!(*found)) return 0;
}

int Graph::DFS(int s,int d){
    bool *visited=new bool[maxn];
    bool found=false;
    int weight=0;
    for(int i=0;i<maxn;i++) visited[i]=false;
    return (DFSUtil(s,d,visited,&found));
}

main(){
    int s,c,q,cas=1;
    int w=0;
    bool blank=false;
    while(cin>>c>>s>>q,c){
        Graph noise(c);
        while(s--){
            int a,b,d;
            cin>>a>>b>>d;
            noise.AddEdge(a,b,d);
        }
        noise.Kruskal();
        if(blank) cout<<endl;
        blank=true;
        cout<<"Case #"<<cas<<endl;
        while(q--){
            int x,y;
            cin>>x>>y;
            w=noise.DFS(x,y);
            if(w) cout<<w<<endl;
            else cout<<"no path\n";
        }
        cas++;
    }
    return 0;
}
