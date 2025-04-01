#include <bits/stdc++.h>
#define eps 1e-8
#define maxn 1010
using namespace std;

struct point
{
    double x,y,z;
    int type,same,diff;
}p[maxn];

struct node
{
    int u,v;
    double d;
    bool operator<(const node& a)const
    {
        return d<a.d;
    }
}d[maxn*maxn];

double dis(point& a,point& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int n;

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            p[i].diff=0,p[i].same=1;
            cin>>p[i].x>>p[i].y>>p[i].z>>p[i].type;
        }
        int num=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                d[num].u=i,d[num].v=j;
                d[num].d=dis(p[i],p[j]);
                num++;
            }
        }
        sort(d,d+num);
        int ans=0,bg=0;
        double R=0;
        for(int i=0;i<num;i++)
        {
            point& a=p[d[i].u];
            point& b=p[d[i].v];
            if(a.type==b.type)
            {
                if(a.same+1==a.diff) bg--;
                if(b.same+1==b.diff) bg--;
                a.same++;
                b.same++;
            }
            else
            {
                if(a.same==a.diff) bg++;
                if(b.same==b.diff) bg++;
                a.diff++;
                b.diff++;
            }
            if(i!=num-1&&fabs(d[i].d-d[i+1].d)<eps) continue;
            if(bg>ans)
            {
                ans=bg;
                R=d[i].d;
            }
        }
        cout<<ans<<endl<<fixed<<setprecision(4)<<R<<endl;
    }
    return 0;
}


/*
4
0 0 0 1
0 1 0 0
1 0 0 0
1 1 0 1
4
0 0 0 1
1 0 0 0
0 1 0 0
0 0 1 1

*/
