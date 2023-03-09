#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
	int a,b;
	while(cin>>a>>b){
		if(a==0&&b==0) break;
		int ans=0,cnt=0;
		while(a>0||b>0){
			cnt=((a%10+b%10)+cnt>9);
			ans+=cnt;
			a/=10,b/=10;
		}
		if(ans==0) cout<<"No carry operation.\n";
        else if(ans==1) cout<<"1 carry operation.\n";
        else cout<<ans<<" carry operations.\n";
	}
	return 0;
}
