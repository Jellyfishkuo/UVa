#include <bits/stdc++.h>
#define int long long
#define maxn 110
using namespace std;

int a[maxn],dp[maxn][maxn],sum[maxn],f[maxn][maxn],g[maxn][maxn];
int n;

int min(int a,int b)
{
    return a<b?a:b;
}

main()
{
    while(cin>>n&&n)
    {
        int i,j,len;
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(i=1;i<=n;i++)
            f[i][i]=g[i][i]=dp[i][i]=a[i];
        for(len=1;len<n;len++)
        {
            for(i=1;i+len<=n;i++)
            {
                j=i+len;
                int m=min(f[i+1][j],g[i][j-1]);
                dp[i][j]=sum[j]-sum[i-1]-min(m,0);
                f[i][j]=min(dp[i][j],f[i+1][j]);
                g[i][j]=min(dp[i][j],g[i][j-1]);
            }
        }
        cout<<2*dp[1][n]-sum[n]<<endl;
    }
    return 0;
}



/*
4
4 -10 -20 7
4
1 2 3 4
0

*/
