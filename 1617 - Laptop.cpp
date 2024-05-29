#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;

struct data{
    int l,r;
    bool operator<(const data& rhs){
        return l<rhs.l||(l==rhs.l&&r<rhs.r);
    }
};

int t,n;
data a[maxn];

main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) cin>>a[i].l>>a[i].r;
        sort(a,a+n);
        int ans=0,r=a[0].r;
        for(int i=0;i<n;i++){
            if(a[i].l>r){
                ans++;
                r=a[i].r;
            }
            else if(a[i].r>r){
                r++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
