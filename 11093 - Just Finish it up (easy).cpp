#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;

int t,n,p[maxn],q[maxn],tc;

main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i) cin>>p[i];
		for(int i=0;i<n;++i) cin>>q[i];
		int sum=0,mn=LLONG_MAX;
		for(int i=0;i<n;++i){
			sum+=p[i]-q[i];
			mn=min(mn,sum);
		}
		int ans=0;
		while(mn<0&&ans<n) mn-=p[ans]-q[ans++];
		cout<<"Case "<<++tc<<": ";
		if(ans==n||sum<0) cout<<"Not possible\n";
		else cout<<"Possible from station "<<ans+1<<'\n';
	}
}
