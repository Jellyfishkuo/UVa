#include<bits/stdc++.h>
#define int long long
using namespace std;

bool dp[205][25];

main(){
    int t,m,c,k,x;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>m>>c>>k;
        for(int i=0;i<k;i++){
            cin>>x;
            if(m>=x) dp[m-x][0]=true;
        }
        for(int i=1;i<c;i++){
            cin>>k;
            while(k--){
                cin>>x;
                for(int j=0;j<=m;j++){
                    if(!dp[j][i-1]) continue;
                    if(j>=x) dp[j-x][i]=true;
                }
            }
        }
        for(x=0;x<=m&&!dp[x][c-1];x++);
        if(x>m) cout<<"no solution\n";
        else cout<<m-x<<endl;
    }
    return 0;
}
