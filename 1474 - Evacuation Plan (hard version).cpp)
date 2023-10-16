#include<bits/stdc++.h>
#define maxn 4000+5
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n,m;

struct node{
    int p,id;
    bool operator<(const node &rhs)const{
        return p<rhs.p;
    }
}t[maxn],s[maxn];

long long dp[2][maxn];
int path[maxn][maxn];
int ans[maxn];

int main(){
    while(cin>>n){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>t[i].p;
            t[i].id=i;
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>s[i].p;
            s[i].id=i;
        }
        sort(t+1,t+n+1);
        sort(s+1,s+m+1);
        for(int j=1;j<=n;j++) dp[0][j]=INF;
        for(int i=1;i<=m;i++){
            dp[i&1][i-1]=INF;
            for(int j=i;j<=n;j++){
                if(dp[(i+1)&1][j-1]<dp[i&1][j-1]){
                    dp[i&1][j]=dp[(i+1)&1][j-1]+abs(t[j].p-s[i].p);
                    path[i][j]=1;
                }
                else{
                    dp[i&1][j]=dp[i&1][j-1]+abs(t[j].p-s[i].p);
                    path[i][j]=0;
                }
            }
        }
        int back_track=m;
        for(int i=n;i>0;i--){
            ans[t[i].id]=s[back_track].id;
            back_track-=path[back_track][i];
        }
        cout<<dp[m&1][n]<<endl;
        for(int i=1;i<=n;i++){
            if(i!=1) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
