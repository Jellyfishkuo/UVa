#include<bits/stdc++.h>
#define maxn 100+5
#define INF 0x3f3f3f3f
using namespace std;

int t,n,r,u,v,s,d;
int dp[maxn][maxn];

void floyd(){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>r;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				dp[i][j]=INF;
				if(i==j) dp[i][j]=0;
			}
		for(int i=0;i<r;i++){
			cin>>u>>v;
			dp[u][v]=dp[v][u]=1;
		}
		floyd();
		int ans=0;
		cin>>s>>d;
		for(int i=0;i<n;i++) ans=max(ans,dp[s][i]+dp[i][d]);
		cout<<"Case "<<i<<": "<<ans<<endl;
	}
	return 0;
}
