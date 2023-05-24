#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        int arr[25],v[1005];
        for(int i=1;i<=p;i++) cin>>arr[i];
        for(int i=1;i<=n;i++) v[i]=0;
        v[0]=1;
        for(int i=1;i<=p;i++)
            for(int j=n;j>=arr[i];--j)
                if(v[j-arr[i]]) v[j]=1;
        if(v[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
