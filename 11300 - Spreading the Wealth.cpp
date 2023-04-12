#include <bits/stdc++.h>
#define maxn 1000000+10
#define int long long
using namespace std;

int arr[maxn],c[maxn],sum,aver,n;

main(){
    while(cin>>n){
        sum=0;
        for(int i=0;i<n;i++) cin>>arr[i],sum+=arr[i];
        aver=sum/n;
        c[0]=0;
        for(int i=0;i<n;i++)c[i+1]=c[i]+arr[i+1]-aver;
        sort(c,c+n);
        int x=c[n/2],ans=0;
        for(int i=0;i<n;i++) ans+=abs(x-c[i]);
        cout<<ans<<endl;
    }
    return 0;
}
