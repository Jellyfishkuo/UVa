#include<bits/stdc++.h>
using namespace std;

int m,n;
int p[5000],f[5000];
int dp[15000];

int main(){
    while(cin>>m>>n){
        memset(dp,0,sizeof(dp));
        if(m>1800) m+=200;
        for(int i=1;i<=n;i++) cin>>p[i]>>f[i];
        for(int i=1;i<=n;i++){
            for(int j=m;j>=p[i];j--){
                dp[j]=max(dp[j-p[i]]+f[i],dp[j]);
            }
        }
        int v=m;
        while(v>0&&dp[v]==dp[v-1]) v--;
        if(v<=2000&&m>2000) cout<<dp[m-200]<<endl;
        else cout<<dp[m]<<endl;
    }
}
