#include <bits/stdc++.h>
#define maxn 200+5
using namespace std;

int Case,c,seg_no,n;
int box[maxn],len[maxn],col[maxn],dp[maxn][maxn][maxn];

int DP(int l,int r,int k){
    if(l>r) return 0;
    if(dp[l][r][k]!=-1) return dp[l][r][k];
    int ans=DP(l,r-1,0)+(len[r]+k)*(len[r]+k);
    for(int i=r-1;i>=l;i--)
        if(col[i]==col[r])
            ans=max(ans,DP(l,i,len[r]+k)+DP(i+1,r-1,0));
    dp[l][r][k]=ans;
    return ans;
}

int main(){
    cin>>Case;
    c=0;
    while(Case--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>box[i];
        seg_no=0,len[seg_no]=1,col[seg_no]=box[0];
        int cur=box[0];
        for(int i=1;i<n;i++){
            if(box[i]==cur) len[seg_no]++;
            else{
                len[++seg_no]=1;
                cur=box[i];
                col[seg_no]=cur;
            }
        }
        seg_no++;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++c<<": "<<DP(0,seg_no-1,0)<<endl;
    }
    return 0;
}
