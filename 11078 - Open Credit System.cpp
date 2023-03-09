#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=arr[0]-arr[1];
        int Maxarri=arr[0];
        for(int i=1;i<n;i++){
            ans=max(ans,Maxarri-arr[i]);
            Maxarri=max(arr[i],Maxarri);
        }
        cout<<ans<<endl;
    }
    return 0;
}
