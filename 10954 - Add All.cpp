#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int n,x;
    while(cin>>n,n){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            cin>>x;
            pq.push(x);
        }
        int ans=0,cnt=0;
        while(pq.size()!=1){
            cnt=pq.top();
            pq.pop();
            cnt+=pq.top();
            pq.pop();
            ans+=cnt;
            pq.push(cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}
