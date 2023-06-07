#include<bits/stdc++.h>
#define int long long
#define maxn 250000
#define fab_mx 22010
using namespace std;

int fab_p[maxn],vis[maxn]={};

main(){
    int n,cnt,a=0,b=1,tmp,i;
    for(i=2,cnt=1;cnt<fab_mx;i++){
        tmp=a+b,a=b,b=tmp;
        while(b>=1e18) a/=10,b/=10;
        if(vis[i]) continue;
        tmp=b;
        while(tmp>=1e9) tmp/=10;
        fab_p[cnt++]=tmp;
        for(int j=i*i;j<maxn;j+=i)
            vis[j]=true;
    }
    fab_p[1]=2,fab_p[2]=3;
    while(cin>>n) cout<<fab_p[n]<<endl;
    return 0;
}
