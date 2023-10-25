#include<bits/stdc++.h>
#define maxn 1000+5
#define int long long
using namespace std;

int a[maxn];
		
main(){
	int t,n;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>0;j--)
				if(a[i]>=a[j]) ans++;
		}
		cout<<ans<<endl;
	}
}
