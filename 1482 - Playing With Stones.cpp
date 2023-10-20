#include<bits/stdc++.h>
#define int long long
using namespace std;

int SG(int x){
    return x%2==0 ? x/2 : SG(x/2);
}

main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,v=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            v^=SG(a);
        }
        if(v) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
