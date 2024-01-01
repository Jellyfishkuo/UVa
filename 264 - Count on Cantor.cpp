#include <bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int n;
    while(cin>>n){
        int term=0,cnt=0;
        while(term<n) term+=cnt++;
        int p=term-n+1;
        cout<<"TERM "<<n<<" IS ";
        if(cnt%2) cout<<cnt-p<<"/"<<p<<endl;
        else cout<<p<<"/"<<cnt-p<<endl;
    }
    return 0;
}
