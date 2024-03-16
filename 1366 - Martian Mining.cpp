#include <bits/stdc++.h>
#define int long long
#define maxn 500+5
using namespace std;

int n,m,x;
int dp[maxn][maxn];
int y[maxn][maxn],b[maxn][maxn];

main(){
    while(cin>>n>>m,n+m){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>x;
                y[i][j]=y[i][j-1]+x;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>x;
                b[i][j]=b[i-1][j]+x;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=max(dp[i-1][j]+y[i][j],dp[i][j-1]+b[i][j]);
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
