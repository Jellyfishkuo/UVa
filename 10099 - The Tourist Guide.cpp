#include<bits/stdc++.h>
#define maxn 110
#define INF 0x3f3f3f3f
using namespace std;

int n,r,u,v,dis,s,d,t,cnt=1;
int dp[maxn][maxn];

void floyd(){
	for(int k=1;k<n+1;k++)
		for(int i=1;i<n+1;i++)
			for(int j=1;j<n+1;j++)
				dp[i][j]=max(dp[i][j],min(dp[i][k],dp[k][j]));
}

int main(){
	while(cin>>n>>r,n){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=0;
		for(int i=0;i<r;i++){
			cin>>u>>v>>dis;
			dp[u][v]=dp[v][u]=dis;
		}
		floyd();		
		cin>>s>>d>>t;
		int ans=t/(dp[s][d]-1);
		if(t%(dp[s][d]-1)) ans++;
		cout<<"Scenario #"<<cnt++<<endl;
		cout<<"Minimum Number of Trips = "<<ans<<endl<<endl;
	}
}
