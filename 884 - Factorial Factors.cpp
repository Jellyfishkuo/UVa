#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;

int n,ans[maxn];

void solve(){
    for(int i=0;i<maxn;i++) ans[i]=1;
    ans[1]=0;
    for(int i=2;i<maxn;i++)
        if(ans[i]==1)
            for(int j=2;i*j<maxn;j++)
                ans[i*j]=ans[i]+ans[j];
    for(int i=2;i<maxn;i++) ans[i]+=ans[i-1];
}

int main(){
    solve();
    while(cin>>n) cout<<ans[n]<<endl;
    return 0;
}
