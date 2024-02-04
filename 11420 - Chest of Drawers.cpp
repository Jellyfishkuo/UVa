#include <bits/stdc++.h>
#define maxn 70
#define int long long
using namespace std;

int n,s;
int dp[maxn+5][maxn+5][2];

main(){
    dp[1][0][0]=1,dp[1][1][1]=1;
    for(int i=2;i<maxn;i++){
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][1];
        for(int j=1;j<=i;j++){
            dp[i][j][0]=dp[i-1][j+1][1]+dp[i-1][j][0];
            dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j-1][0];
        }
    }
    while(cin>>n>>s){
        if(n<0||s<0) break;
        cout<<dp[n][s][0]+dp[n][s][1]<<endl;
    }
    return 0;
}
