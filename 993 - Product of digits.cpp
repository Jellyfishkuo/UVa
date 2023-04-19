#include<bits/stdc++.h>
#define maxn 100000
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0,ans[maxn];
		if(n==1) cout<<1;
		else{
			for(int i=9;i>1;i--){
				while(n%i==0){
					n/=i;
					ans[cnt++]=i;
				}
			}
			sort(ans,ans+cnt);
			if(n==1) for(int i=0;i<cnt;i++) cout<<ans[i];
			else cout<<"-1";
		}
		cout<<endl;
	}
}
