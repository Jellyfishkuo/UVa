#include <bits/stdc++.h>
#define maxn 30
using namespace std;

int SG[maxn];
int vis[1005];
int pile[maxn],ans;

void CalculateSG()
{
    SG[0]=0;
    for(int i=1;i<=maxn;i++)
    {
        int cur=0;
        for(int j=0;j<i;j++)
            for(int k=0;k<=j;k++)
            vis[SG[j]^SG[k]]=i;
        while(vis[cur]==i) cur++;
        SG[i]=cur;
    }
}

int main()
{
    CalculateSG();
    int cas=0,n;
    while(cin>>n&&n)
    {
        ans=0;
        for(int i=1;i<=n;i++) cin>>pile[i];
        for(int i=1;i<=n;i++)
            if(pile[i]&1)
                ans^=SG[n-i];
        cout<<"Game "<<++cas<<": ";
        if(!ans) cout<<"-1 -1 -1\n";
        else
        {
            bool f=0;
            for(int i=1;i<=n;i++)
            {
                if(pile[i])
                {
                    for(int j=i+1;j<=n;j++)
                    {
                        for(int k=j;k<=n;k++)
                        {
                            if((SG[n-i]^SG[n-j]^SG[n-k])==ans)
                            {
                                cout<<i-1<<" "<<j-1<<" "<<k-1<<endl;
                                f=1;
                                break;
                            }
                        }
                        if(f) break;
                    }
                    if(f) break;
                }
            }
        }
    }
    return 0;
}


/*
4
1 0 1 100
3
1 0 5
2
2 1
0

*/
