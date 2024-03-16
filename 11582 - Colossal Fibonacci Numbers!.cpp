#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int t,a,b,n;
int f[1000*1000+500];

int pow_mod(int a,int b,int n){
    if(b==0) return 1;
    int ans=pow_mod(a,b/2,n);
    ans=ans*ans%n;
    if(b%2) ans=ans*a%n;
    return ans;
}


main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        f[0]=0,f[1]=1%n;
        int period=1;
        for(int i=2;i<n*n+100;i++){
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i-1]==f[0]&&f[i]==f[1]){
                period=i-1;
                break;
            }
        }
        int ans=pow_mod(a%period,b,period);
        cout<<f[ans]<<endl;
    }
    return 0;
}
