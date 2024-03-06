#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;

int arr[maxn];

main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int l=0,r=n-1,ans=0;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        while(l<r){
            if(arr[r]+arr[r-1]<=m) r-=2;
            else if(arr[l]+arr[r]<=m) l++,r--;
            else r--;
            ans++;
        }
        if(l==r) ans++;
        cout<<ans<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
