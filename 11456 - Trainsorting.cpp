#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0,arr[n],lis[n],lds[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=n-1;i>=0;i--){
            lis[i]=1,lds[i]=1;
            for(int j=n-1;j>i;j--){
                if(arr[i]<arr[j])
                    lds[i]=max(lds[i],lds[j]+1);
                else
                    lis[i]=max(lis[i],lis[j]+1);
            }
        }
        for(int i=0;i<n;i++)
            ans=max(lis[i]+lds[i]-1,ans);
        cout<<ans<<endl;
    }
    return 0;
}
