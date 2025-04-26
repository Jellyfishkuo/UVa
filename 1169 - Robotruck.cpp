#include <bits/stdc++.h>
#define maxn 100005
#define INF 0x3f3f3f3f
using namespace std;

int x[maxn],y[maxn];
int d2o[maxn],total_dist[maxn],total_weight[maxn];
int d[maxn];

int f(int j)
{
    return d[j]-total_dist[j+1]+d2o[j+1];
}

int cas,c,n,w;

int main()
{
    cin>>cas;
    while(cas--)
    {
        cin>>c>>n;
        total_dist[0]=total_weight[0]=x[0]=y[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i]>>w;
            d2o[i]=abs(x[i])+abs(y[i]);
            total_dist[i]=total_dist[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            total_weight[i]=total_weight[i-1]+w;
        }
        deque<int> q;
        q.push_back(0);
        for(int i=1;i<=n;i++)
        {
            while(!q.empty()&&(total_weight[i]-total_weight[q.front()]>c))
                q.pop_front();
            d[i]=f(q.front())+total_dist[i]+d2o[i];
            while(!q.empty()&&(f(q.back())>=f(i)))
                q.pop_back();
            q.push_back(i);
        }
        cout<<d[n]<<endl;
        if(cas) cout<<endl;
    }
    return 0;
}


/*
2

10
4
1 2 3
1 0 3
3 1 4
3 1 4

10
4
1 2 3
1 0 3
3 1 4
3 1 4

*/
