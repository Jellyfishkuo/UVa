#include <bits/stdc++.h>
#define maxn 1000010
#define INF 0x3f3f3f3f
using namespace std;

int t,n,m,k,cas,a[maxn],cnt[maxn];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        memset(cnt,0,sizeof(cnt));
        a[1]=1,a[2]=2,a[3]=3;
        for(int i=4;i<=n;i++) a[i]=(a[i-1]+a[i-2]+a[i-3])%m+1;
        int ans=INF;
        int rear=0,last=1,c=0;
        while(1)
        {
            if(c==k)
            {
                cnt[a[last]]--;
                if(cnt[a[last]]==0&&a[last]<=k) c--;
                last++;
                if(c==k) ans=min(ans,rear-last+1);
            }
            else
            {
                rear++;
                if(rear>n) break;
                cnt[a[rear]]++;
                if(cnt[a[rear]]==1&&a[rear]<=k) c++;
                if(c==k) ans=min(ans,rear-last+1);
            }
        }
        cout<<"Case "<<++cas<<": ";
        if(ans!=INF) cout<<ans<<endl;
        else cout<<"sequence nai\n";
    }
    return 0;
}


/*
2
20 12 4
20 12 8

*/
