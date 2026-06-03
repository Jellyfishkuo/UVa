#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn=6e4+7;
int m,n,h[maxn];

struct Point
{
    int x,y;
}A,B;

int main()
{
    int cas,x,y;
    cin>>cas;
    while(cas--)
    {
        memset(h,INF,sizeof(h));
        cin>>m>>n;
        cin>>A.x>>A.y;
        cin>>B.x>>B.y;
        for(int i=3;i<=n;i++)
        {
            cin>>x>>y;
            if(x<A.x||x>B.x) continue;
            h[x]=min(h[x],abs(y-A.y)-1);
        }
        h[A.x]=-1;
        for(int i=A.x+1;i<B.x;i++) h[i]=min(h[i-1]+1,h[i]);
        h[B.x]=-1;
        for(int i=B.x-1;i>A.x;i--) h[i]=min(h[i+1]+1,h[i]);
        long long ans=0;
        for(int i=A.x+1;i<B.x;i++)
        {
            if(h[i]==-1) continue;
            int high=min(A.y+h[i],m-1);
            int low=max(A.y-h[i],0);
            ans+=high-low+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}


/*
2
6 3
1 3
4 3
0 2
11 11
0 5
10 5
4 9
2 8
7 8
5 6
3 5
5 3
3 2
7 2
9 1

*/
