#include<bits/stdc++.h>
#define maxP 20010
#define INF 0x3f3f3f3f
using namespace std;

int t,p,n;
int c[200],dp[maxP];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>p>>n;
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++)
            for(int w=maxP;w>0;w--)
                if(w>=c[i]&&dp[w-c[i]]+1<dp[w])
                    dp[w]=dp[w-c[i]]+1;
        int ans;
        for(ans=p;dp[ans]==INF;ans++);
        cout<<ans<<" "<<dp[ans]<<endl;
    }
    return 0;
}

/*
1
1400
3
500
1000
2000

*/

