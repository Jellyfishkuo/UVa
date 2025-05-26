#include <bits/stdc++.h>
#define maxn 205
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int u,v,d;
    // d==0 undirected, d==1 forward, d==2 backward
    Edge(int u=0,int v=0,int d=0):u(u),v(v),d(d){}
 };

vector<Edge> G[maxn];
int n,root,maxlen,f[maxn],b[maxn]; // forward,backward
bool p[maxn];

int dfs(int u)
{
    int ans=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].v;
        if(G[u][i].d==1) ans=max(ans,dfs(v)+1);
    }
    return ans;
}

bool read_data()
{
    bool have_data=false;
    int u,v;
    char ch;
    n=0;
    for(int i=0;i<maxn;i++) G[i].clear();
    memset(p,0,sizeof(p));
    while(scanf("%d",&u)==1&&u)
    {
        have_data=true;
        if(u>n) n=u;
        while(scanf("%d%c",&v,&ch)==2&&v)
        {
            if(v>n) n=v;
            p[v]=true;
            if(ch=='d')
            {
                G[u].push_back(Edge(u,v,1)); // forward
                G[v].push_back(Edge(v,u,2)); // backward
            }
            else if(ch=='u')
            {
                G[u].push_back(Edge(u,v,2));
                G[v].push_back(Edge(v,u,1));
            }
            else
            {
                G[u].push_back(Edge(u,v,0)); // it's a rooted tree, so we don't store edge to father
            }
        }
    }
    if(have_data)
    {
        for(int i=1;i<=n;i++)
        {
            if(!p[i]&&!G[i].empty())
            {
                root=i;
                break;
            }
        }
    }
    return have_data;
}

struct uds
{
    int w,f,b;
    uds(int w=0,int f=0,int b=0):w(w),f(f),b(b){}
};

bool fcmp(const uds& a,const uds& b)
{
    return a.f<b.f;
}

bool bcmp(const uds& a,const uds& b)
{
    return a.b<b.b;
}

bool dp(int i,int fa)
{
    if(G[i].empty())
    {
        f[i]=b[i]=0;
        return true;
    }

    vector<uds> children;
    int f0=0,b0=0;

    for(int k=0;k<G[i].size();k++)
    {
         int w=G[i][k].v;
         if(w==fa) continue;
         dp(w,i);

         int d=G[i][k].d;
         if(d==0) children.push_back(uds(w,f[w],b[w]));
         else if(d==1) f0=max(f0,f[w]+1);
         else b0=max(b0,b[w]+1);
    }

    if(children.empty())
    {
        f[i]=f0;
        b[i]=b0;
        if(f[i]+b[i]>maxlen) f[i]=b[i]=INF;
        return f[i]<INF;
    }

    f[i]=b[i]=INF;
    int und_size=children.size();
    sort(children.begin(), children.end(), static_cast<bool(*)(const uds&, const uds&)>(fcmp));
    int maxb[maxn];
    maxb[und_size-1]=children[und_size-1].b;
    for(int k=und_size-2;k>=0;k--)
        maxb[k]=max(children[k].b,maxb[k+1]);
    for(int p=0;p<=children.size();p++)
    {
        int ff=f0,bb=b0;
        if(p>0) ff=max(ff,children[p-1].f+1);
        if(p<children.size()) bb=max(bb, maxb[p]+1);
        if(ff+bb<=maxlen) f[i]=min(f[i],ff);
    }
    sort(children.begin(), children.end(), static_cast<bool(*)(const uds&, const uds&)>(bcmp));
    int maxf[maxn];
    maxf[und_size-1]=children[und_size-1].f;
    for(int k=und_size-2;k>=0;k--)
        maxf[k]=max(children[k].f,maxf[k+1]);
    for(int p=0;p<=children.size();p++)
    {
        int ff=f0,bb=b0;
        if(p>0) bb=max(bb, children[p-1].b+1);
        if(p<children.size()) ff=max(ff,maxf[p]+1);
        if(ff+bb<=maxlen) b[i]=min(b[i],bb);
    }
    return f[i]<INF;
}

int main()
{
    while(read_data())
    {
        maxlen=0;
        for(int i=1;i<=n;i++) maxlen=max(maxlen,dfs(i));
        if(dp(root,-1)) cout<<maxlen+1<<endl;
        else cout<<maxlen+2<<endl;
   }
   return 0;
}



/*
1 2 3d 0
2 4d 0
3 5d 0
4 6d 0
0
1 2d 3u 4 0
0
1 2d 3 0
2 4d 5d 10 0
3 6d 7d 11 0
6 8d 9 12 0
0
1 2 3 4 0
2 5d 0
3 6d 0
4 7d 0
5 8d 0
6 9d 0
7 10d 0
0
0

*/
