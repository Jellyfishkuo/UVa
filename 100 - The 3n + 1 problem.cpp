#include<bits/stdc++.h>
#define int long long
using namespace std;

int f(int n){
	int ans=1;
	while(n!=1){
		if(n%2) n=n*3+1;
		else n/=2;
		ans++;
	}
	return ans;
}

main(){
	int i,j;
	while(cin>>i>>j){
		cout<<i<<" "<<j<<" ";
		if(j<i){
			int cmp=i;
			i=j;
			j=cmp;
		}
		int ans=0;
		for(int k=i;k<=j;k++) ans=max(ans,f(k));
		cout<<ans<<endl;
	}
	return 0;
}
