#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int len,n;
int arr[maxn];
int dp[maxn][maxn];


int solve(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l+1==r) return dp[l][r]=0;
    int sum=0x3f3f3f3f;
    for(int i=l+1;i<r;i++)
        sum=min(sum,solve(l,i)+solve(i,r));
    return dp[l][r]=sum+arr[r]-arr[l];
}

int main(){
    while(cin>>len,len){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        arr[0]=0,arr[n+1]=len;
        memset(dp,-1,sizeof(dp));
        cout<<"The minimum cutting is "<<solve(0,n+1)<<".\n";
    }
    return 0;
}
