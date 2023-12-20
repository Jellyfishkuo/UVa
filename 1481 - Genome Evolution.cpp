#include <bits/stdc++.h>
#define maxn 3000+5
using namespace std;

int n,v[maxn],a[maxn];
int solve(){
    int l,r,k,ans=0;
    for(int i=0;i<n;i++){
        l=r=v[a[i]];
        k=1;
        for(int j=i+1;j<n;j++){
            l=min(l,v[a[j]]);
            r=max(r,v[a[j]]);
            k++;
            if(r-l+1==k) ans++;
        }
    }
    return ans;
}

int main(){
    while(cin>>n,n){
        int k;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>k;
            v[k]=i;
        }
        cout<<solve()<<endl;
    }
    return 0;
}
