#include <bits/stdc++.h>
#define maxn 5010
#define INF 0x3f3f3f3f;
using namespace std;

double pi=acos(-1.0);

struct node{
    int x,y,cnt;
    double r,t;
}p[maxn],sec[maxn];

int N,K,cnt;
bool cmp_r(const node &a,const node &b)
{
    return a.r<b.r;
}
bool cmp_t(const node &a,const node &b)
{
    return a.t<b.t;
}

double solve()
{
    if(K==0) return 0;
    sort(p,p+N,cmp_t);
    double ans=INF;
    set<double> v;
    for(int i=0;i<N;i++)
    {
        if(p[i].cnt<K) continue;
        double R=p[i].r,T=2*pi;
        if(v.find(R)!=v.end()) continue;
        v.insert(R);
        int idx=0;
        for(int i=0;i<N;i++)
        {
            if(p[i].r<R||fabs(p[i].r-R)<1e-9)
            {
                sec[idx++]=p[i];
                if(idx>=K) T=min(T,sec[idx-1].t-sec[idx-K].t);
            }
        }
        if(idx<K) continue;
        for(int i=0;i<K-1;i++) T=min(T,sec[i].t-sec[idx+i-K+1].t+2*pi);
        ans=min(ans,R*R*T/2);
    }
    return ans;
}

int main()
{
    int cas=0;
    while(cin>>N>>K)
    {
        if(N+K==0) break;
        for(int i=0;i<N;i++)
        {
            cin>>p[i].x>>p[i].y;
            p[i].r=sqrt(p[i].x*p[i].x*1.0+p[i].y*p[i].y*1.0);
            p[i].t=atan2(p[i].y,p[i].x);
            p[i].cnt=1;
        }
        sort(p,p+N,cmp_r);
        for(int i=1;i<N;i++) p[i].cnt+=p[i-1].cnt;
        cout<<"Case #"<<++cas<<": ";
        cout<<fixed<<setprecision(2)<<solve()<<endl;
    }
    return 0;
}


/*
3 1
0 1
1 0
-5 -6

3 2
0 2
2 0
-5 -6

0 0

*/
