#include<bits/stdc++.h>
#define int long long
using namespace std;

int f(int n){
    if(n<10) return n;
    int cnt=0;
    while(n>0){
        cnt+=n%10;
        n/=10;
    }
    return f(cnt);
}

main(){
    int n;
    while(cin>>n,n) cout<<f(n)<<endl;
    return 0;
}
