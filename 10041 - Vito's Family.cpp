#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],mid=n/2;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=abs(a[i]-a[mid]);
		cout<<ans<<endl;
	}
	return 0;
}
