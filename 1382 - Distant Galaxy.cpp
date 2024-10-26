#include<bits/stdc++.h>
#define maxn 110
using namespace std;

struct Point
{
    int x,y;
    bool operator<(const Point& rhs) const
    {
        return x<rhs.x;
    }
};

Point P[maxn];
int n,m,y[maxn],on[maxn],on2[maxn],Left[maxn];
int solve()
{
    sort(P,P+n);
    sort(y,y+n);
    m=unique(y,y+n)-y;
    if(m<=2) return n;
    int ans=0;
    for(int a=0;a<m;a++)
        for(int b=a+1;b<m;b++)
        {
            int ymin=y[a],ymax=y[b];
            int k=0;
            for(int i=0;i<n;i++)
            {
                if(i==0||P[i].x!=P[i-1].x)
                {
                    k++;
                    on[k]=on2[k]=0;
                    Left[k]=k==0?0:Left[k-1]+on2[k-1]-on[k-1];
                }
                if(P[i].y>ymin&&P[i].y<ymax) on[k]++;
                if(P[i].y>=ymin&&P[i].y<=ymax) on2[k]++;
            }
            if(k<=2) return n;
            int M=0;
            for(int j=1;j<=k;j++)
            {
                ans=max(ans,Left[j]+on2[j]+M);
                M=max(M,on[j]-Left[j]);
            }
        }
    return ans;
}

int main()
{
    int cas = 0;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>P[i].x>>P[i].y;
            y[i]=P[i].y;
        }
        cout<<"Case "<<++cas<<": "<<solve()<<endl;
    }
    return 0;
}

/*
10
2 3
9 2
7 4
3 4
5 7
1 5
10 4
10 6
11 4
4 6
0

*/
